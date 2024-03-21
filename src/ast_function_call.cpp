#include "ast_function_call.hpp"

void FunctionCall::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    // load arguments into registers
    if(args_!=nullptr){
        context.freeParamRegs();
        args_->EmitRISC(stream, context, destReg);
        context.freeParamRegs();
    }

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




    // call function
    std::string f_name = name_->ReturnID();
    // go into context and find this variable with all its parameters
    // in the new scope, set up the variables for this
    // you need to allocate memory space for them too
    std::map<std::string, std::string> param_list = context.returnParamList(f_name);
    for(auto it  = param_list.begin(); it != param_list.end(); it++){
        context.allocateVariable(it->first, it->second);
    }




    stream << "call " << f_name << std::endl;
    stream << "mv x" << destReg << ", a0" << std::endl;
    //stream << "addi sp, sp, " << context.getFunctionSize(f_name) << std::endl;






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

    context.variables.pop_back();
    context.variable_allocs.pop_back();
}

void FunctionCall::Print(std::ostream &stream) const {}

 int FunctionCall::getSize() const{
    /* get f_type from context probably
    if(f_type=="char"){
        return 1;
    }
    else if(f_type=="float"){
        return 8;
    }
    else if(f_type=="double"){
        return 4;
    }
    else{
        return 4;
    }
    */
}

void FunctionCall::isFunction(Context &context) const{
    context.isFunctionCall();
}
