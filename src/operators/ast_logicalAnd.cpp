#include "ast/operators/ast_logicalAnd.hpp"

void LogicAnd::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    std::string branch0 = context.createBranch();
    std::string branchOut = context.createBranch();

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);

    stream << "li x" << destReg << ", 1" << std::endl;
    stream << "beq x" << left_reg << ", " << "zero, ." << branch0 << std::endl;
    stream << "beq x" << right_reg << ", " << "zero, ." << branch0 << std::endl;
    stream << "j ." << branchOut << std::endl;
    stream << "." << branch0 << ":" << std::endl;
    stream << "li x" << destReg << ", 0" << std::endl;
    stream << "j ." << branchOut << std::endl;
    stream << "." << branchOut << ":" << std::endl;

    context.freeRegister(left_reg);
    context.freeRegister(right_reg);
}

void LogicAnd::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << " && ";
    right_->Print(stream);
}
void LogicAnd::isFunction(Context &context) const{
    left_->isFunction(context);
    right_->isFunction(context);
}

int LogicAnd::getValue() const{
    return left_->getValue() && right_->getValue();
}