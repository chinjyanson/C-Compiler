#include "ast/operators/ast_unary_op.hpp"

void UnaryOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    expr_->EmitRISC(stream, context, destReg);
    u_op_->EmitRISC(stream, context, destReg);
}

void UnaryOp::Print(std::ostream &stream) const {
}
void UnaryOp::isFunction(Context &context) const{
    expr_->isFunction(context);
}
