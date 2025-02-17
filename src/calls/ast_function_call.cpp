#include "ast/calls/ast_function_call.hpp"

void FunctionCall::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    /* // Store current state of context
    int old_mem_offset = context.mem_offset;
    std::vector<std::map<std::string, std::string>> old_variables;
    for (auto& scope : context.variables) {
        old_variables.push_back(std::move(scope));
    }
    std::vector<std::map<std::string, int>> old_allocs;
    for (auto& scope : context.variable_allocs) {
        old_allocs.push_back(std::move(scope));
    }
    // Flush context
    context.variables.clear();
    context.variable_allocs.clear();
    stream << "addi s0, s0, " << old_mem_offset+16 << std::endl;
    context.mem_offset = -16; */

    // Set up new space
    context.variables.push_back(std::map<std::string, std::string>());
    context.variable_allocs.push_back(std::map<std::string, int>());
    context.pointers.push_back(std::vector<std::string>());
    context.arrays.push_back(std::map<std::string, int>());

    // call function
    std::string f_name = name_->ReturnID();
    if(args_!=nullptr){
        context.freeParamRegs();
        args_->EmitRISC(stream, context, destReg);
        context.freeParamRegs();

        std::map<std::string, std::string> param_list = context.returnParamList(f_name);
        for(auto it  = param_list.begin(); it != param_list.end(); it++){
            context.allocateVariable(it->first, it->second);
        }
    }

    stream << "call " << f_name << std::endl;
    stream << "mv x" << destReg << ", a0" << std::endl;

    context.variables.pop_back();
    context.variable_allocs.pop_back();
    context.pointers.pop_back();
    context.arrays.pop_back();

    /* // Restore context
    stream << "addi s0, s0, " << -(old_mem_offset+16) << std::endl;
    context.mem_offset = old_mem_offset;

    for (auto& scope : old_variables) {
        context.variables.push_back(std::move(scope));
    }
    old_variables.clear();
    for (auto& scope : old_allocs) {
        context.variable_allocs.push_back(std::move(scope));
    }
    old_allocs.clear(); */
}

void FunctionCall::Print(std::ostream &stream) const {
    stream << name_->ReturnID() << "(";
    if(args_!=nullptr){
        args_->Print(stream);
    }
    stream << ")";
}

 int FunctionCall::getSize(Context &context) const{
    std::string f_type = context.getFunctionType(name_->ReturnID());
    if(f_type=="char"){
        return 1;
    }
    else if(f_type=="long"){
        return 8;
    }
    else if(f_type=="double"){
        return 8;
    }
    else{
        return 4;
    }
}

void FunctionCall::isFunction(Context &context) const{
    context.isFunctionCall();
}
