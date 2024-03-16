#include "ast_assign_op.hpp"

void AssignOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int expr_reg = context.getFreeRegister();

    var_->EmitRISC(stream, context, destReg);
    expr_->EmitRISC(stream, context, expr_reg);
    stream << "mv x" << destReg << ", x" << expr_reg << std::endl;
    var_->UpdateVar(stream, context, destReg);
    context.freeRegister(expr_reg);

}

void AssignOp::Print(std::ostream &stream) const {
}
