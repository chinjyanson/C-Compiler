#include "ast_while.hpp"

void WhileLoop::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    int condition_reg = context.getFreeRegister();
    std::string branchCheck = context.createBranch();
    std::string branchLoop = context.createBranch();

    if(is_do_){
        statement1_->EmitRISC(stream, context, destReg);
    }

    stream << "j ." << branchCheck << std::endl;
    stream << "." << branchLoop << ":" << std::endl;
    statement1_->EmitRISC(stream, context, destReg);
    stream << "." << branchCheck << ":" << std::endl;
    condition_->EmitRISC(stream, context, condition_reg);
    stream << "bne x" << condition_reg << ", zero, ." << branchLoop << std::endl;

}

void WhileLoop::Print(std::ostream &stream) const
{
    stream << "while(";
    condition_->Print(stream);
    stream << ") ";
    statement1_->Print(stream);
}

void WhileLoop::isFunction(Context &context) const{
    condition_->isFunction(context);
    statement1_->isFunction(context);
}
