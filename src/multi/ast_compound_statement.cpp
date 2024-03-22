#include "ast/multi/ast_compound_statement.hpp"

void CompStatement::EmitRISC(std::ostream &stream, Context &context, int destReg) const {
    if(branch_ != nullptr){
        bool old_scope = context.function_scope;
        if(!context.function_scope){
            context.variables.push_back(std::map<std::string, std::string>());
            context.variable_allocs.push_back(std::map<std::string, int>());
            context.pointers.push_back(std::vector<std::string>());
        }

        context.function_scope = false;
        branch_->EmitRISC(stream, context, destReg);
        context.function_scope = old_scope;

        if(!context.function_scope){
            context.variables.pop_back();
            context.variable_allocs.pop_back();
            context.pointers.pop_back();
        }
    }
    else{
        std::cerr << "Error: Empty compound statement" << std::endl;
    }
}

void CompStatement::Print(std::ostream &stream)const {
    stream << "{";
    branch_->Print(stream);
    stream << "}";
}

void CompStatement::mapVars(Context &context) const{
    branch_->mapVars(context);
}
void CompStatement::isFunction(Context &context) const{
    branch_->isFunction(context);
}
