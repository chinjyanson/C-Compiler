#include "ast/operators/ast_lt_op.hpp"

void LtOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);
    stream << "slt x" << destReg << ", x" << left_reg << ", x"<< right_reg << std::endl;

    context.freeRegister(left_reg);
    context.freeRegister(right_reg);
}

void LtOp::Print(std::ostream &stream) const {
    left_->Print(stream);
    stream << " > ";
    right_->Print(stream);
}
void LtOp::isFunction(Context &context) const{
    left_->isFunction(context);
    right_->isFunction(context);
}
