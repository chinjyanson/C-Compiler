#include "ast/operators/ast_divide_op.hpp"

void DivideOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);
    stream << "div x" << destReg << ", x" << left_reg << ", x"<< right_reg << std::endl;

    context.freeRegister(left_reg);
    context.freeRegister(right_reg);
}

void DivideOp::Print(std::ostream &stream) const {
    left_->Print(stream);
    stream << " / ";
    right_->Print(stream);
}

void DivideOp::isFunction(Context &context) const{
    left_->isFunction(context);
    right_->isFunction(context);
}

int DivideOp::getValue() const{
    return left_->getValue() / right_->getValue();
}