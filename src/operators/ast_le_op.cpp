#include "ast/operators/ast_le_op.hpp"

void LeOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);
    stream << "slt x" << destReg << ", x" << left_reg << ", x"<< right_reg << std::endl;
    stream << "sub x" << left_reg << ", x" << left_reg << ", x"<< right_reg << std::endl;
    stream << "seqz x" << left_reg << ", x" << left_reg << std::endl;
    stream << "or x" << destReg << ", x" << left_reg << ", x"<< destReg << std::endl;

    context.freeRegister(left_reg);
    context.freeRegister(right_reg);
}

void LeOp::Print(std::ostream &stream) const {
    left_->Print(stream);
    stream << " <= ";
    right_->Print(stream);
}

void LeOp::isFunction(Context &context) const{
    left_->isFunction(context);
    right_->isFunction(context);
}
