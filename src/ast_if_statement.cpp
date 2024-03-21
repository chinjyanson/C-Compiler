#include "ast_if_statement.hpp"

void IfStatement::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    int condition_reg = context.getFreeRegister();
    std::string branch0 = context.createBranch();
    std::string branchOut = context.createBranch();

    condition_->EmitRISC(stream, context, condition_reg);

    stream << "beq x" << condition_reg << ", zero, ." << branch0 << std::endl;
    statement1_->EmitRISC(stream, context, destReg);
    stream << "j ." << branchOut << std::endl;
    stream << "." << branch0 << ":" << std::endl;
    if(statement0_ != nullptr){
        statement0_->EmitRISC(stream, context, destReg);
    }
    stream << "." << branchOut << ":" << std::endl;



}

void IfStatement::Print(std::ostream &stream) const
{
}

void IfStatement::isFunction(Context &context) const{
    condition_->isFunction(context);
    statement0_->isFunction(context);
    statement1_->isFunction(context);
};
