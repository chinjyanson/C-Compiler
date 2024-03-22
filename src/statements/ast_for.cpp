#include "ast/statements/ast_for.hpp"

void ForLoop::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    int condition_reg = context.getFreeRegister();
    std::string branchCheck = context.createBranch();
    std::string branchLoop = context.createBranch();

    init_->EmitRISC(stream, context, destReg);
    stream << "j ." << branchCheck << std::endl;
    stream << "." << branchLoop << ":" << std::endl;
    if(statement_ != nullptr){
        statement_->EmitRISC(stream, context, destReg);
        increment_->EmitRISC(stream, context, destReg);
    }
    stream << "." << branchCheck << ":" << std::endl;
    condition_->EmitRISC(stream, context, condition_reg);
    stream << "bne x" << condition_reg << ", zero, ." << branchLoop << std::endl;
}

void::ForLoop::Print(std::ostream &stream) const
{
    stream << "for(";
    init_->Print(stream);
    stream << "; ";
    condition_->Print(stream);
    stream << "; ";
    increment_->Print(stream);
    stream << ") ";
    if(statement_ != nullptr){
        statement_->Print(stream);
    }
}

void ForLoop::isFunction(Context &context) const{
    condition_->isFunction(context);
    init_->isFunction(context);
    statement_->isFunction(context);
};
void ForLoop::mapVars(Context &context) const{
    condition_->mapVars(context);
    statement_->isFunction(context);
    init_->mapVars(context);
}
