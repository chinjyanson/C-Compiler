#include "ast/operators/ast_gt_op.hpp"

void GtOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);
    stream << "slt x" << destReg << ", x" << right_reg << ", x"<< left_reg << std::endl;

    context.freeRegister(left_reg);
    context.freeRegister(right_reg);
}

void GtOp::Print(std::ostream &stream) const {
    left_->Print(stream);
    stream << " > ";
    right_->Print(stream);
}

void GtOp::isFunction(Context &context) const{
    left_->isFunction(context);
    right_->isFunction(context);
}

