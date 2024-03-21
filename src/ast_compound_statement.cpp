#include "ast_compound_statement.hpp"

void CompStatement::EmitRISC(std::ostream &stream, Context &context, int destReg) const {
    if(branch_ != nullptr){

        if(!context.is_function){
            context.variables.push_back(std::map<std::string, std::string>());
            context.variable_allocs.push_back(std::map<std::string, int>());
        }

        branch_->EmitRISC(stream, context, destReg);

        if(!context.is_function){
            context.variables.pop_back();
            context.variable_allocs.pop_back();
        }
    }

}

void CompStatement::Print(std::ostream &stream) const {
    stream << "{";
    branch_->Print(stream);
    stream << "}";
}

void CompStatement::mapVars(Context &context) const{
    branch_->mapVars(context);
}
