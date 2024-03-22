#include "ast/declarations/ast_function_definition.hpp"

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    // Set up new space
    context.variables.push_back(std::map<std::string, std::string>());
    context.variable_allocs.push_back(std::map<std::string, int>());
    context.pointers.push_back(std::vector<std::string>());
    context.arrays.push_back(std::map<std::string, int>());
    context.function_scope = true;

    std::string func_name = declarator_->ReturnID();
    std::string func_type = declaration_specifiers_->returnType();
    std::string endLabel = context.createLabel();
    context.addFunction(func_name, func_type);

    declarator_->mapParams(context); // this will put it in the function thing dw
    compound_statement_->mapVars(context);
    context.addFunctionVars(func_name);
    context.clearTempVars();

    compound_statement_->isFunction(context);
    int is_call = context.is_function;

    stream << ".text" << std::endl;
    stream << ".globl " << func_name << std::endl;
    stream << func_name << ":" << std::endl;

    int stacksize = context.checkFunctionSize(func_name);
    stacksize = context.roundStackSize(stacksize);

    stream << "addi sp, sp, -" << stacksize <<std::endl;

    if(is_call){
        stream << "sw ra, " << stacksize - 4 << "(sp)" << std::endl;
    }
    else{
        is_call = 0;
    }

    if (func_type == "double"){
        stream << "sw s0, "<< stacksize - (is_call*4) - 8 <<"(sp)" << std::endl;
    }
    else if (func_type == "float"){
        stream << "sw s0, "<< stacksize - (is_call*4)- 8 <<"(sp)" << std::endl;
    }
    else{
        stream << "sw s0, "<< stacksize - (is_call*4) - 4 <<"(sp)" << std::endl;
    }

    stream << "addi s0, sp, " << stacksize << std::endl;

    int tempReg = context.getFreeRegister();

    declarator_->EmitRISC(stream, context, tempReg); // start param setup? like the allocate thing i think
    //stream << "sw ra, -8(s0)" << std::endl;
    if (compound_statement_ != nullptr)
    {
        compound_statement_->EmitRISC(stream, context, tempReg);
    }

    stream << "." << endLabel << ":" << std::endl;

    if(is_call){
        stream << "lw ra, " << stacksize - 4 <<"(sp)" << std::endl;
    }

    if (func_type == "double"){
        stream << "fmv.d fa0, fx" << tempReg << std::endl;
        stream << "lw s0,"<< stacksize - (is_call*4) - 8 << "(sp)" << std::endl;
    }
    else if (func_type == "float"){
        stream << "fmv.s fa0, fx" << tempReg << std::endl;
        stream << "lw s0,"<< stacksize - (is_call*4) - 8 << "(sp)" << std::endl;
    }
    else{
        stream << "mv a0, x" << tempReg << std::endl;
        stream << "lw s0, "<< stacksize - (is_call*4) - 4 << "(sp)" << std::endl;
    }

    stream << "addi sp, sp, " << stacksize << std::endl;
    stream << "jr ra" << std::endl;

    context.variables.pop_back();
    context.variable_allocs.pop_back();
    context.pointers.pop_back();
    context.arrays.pop_back();
    context.function_scope = false;


    /* int new_mem_offset = context.mem_offset;
    context.setFunctionSize(func_name, old_mem_offset-new_mem_offset);
    //stream << "addi sp, sp, " << context.getFunctionSize(func_name) << std::endl;
    // context.mem_offset = old_mem_offset;
    context.variables.pop_back();
    context.variable_allocs.pop_back(); */

    //stream << "lw ra, -16(s0)" << std::endl;
    //stream << "ret" << std::endl;

}

void FunctionDefinition::Print(std::ostream &stream) const
{
    declaration_specifiers_->Print(stream);
    stream << " ";

    declarator_->Print(stream);
    stream << "() {" << std::endl;

    if (compound_statement_ != nullptr)
    {
        compound_statement_->Print(stream);
    }
    stream << "}" << std::endl;
}
