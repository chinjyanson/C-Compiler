#include "ast/operators/ast_unary_op.hpp"

void UnaryOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    std::string sign = u_op_->ReturnID();
    if(sign=="&"){
        std::string var_name = expr_->ReturnID();
        int mem_offset = context.findVariable(var_name);
        stream << "addi x" << destReg << ", s0, " << mem_offset << std::endl;
    }
    else{
        expr_->EmitRISC(stream, context, destReg);
        u_op_->EmitRISC(stream, context, destReg);
    }

}

void UnaryOp::Print(std::ostream &stream) const {
}
void UnaryOp::isFunction(Context &context) const{
    expr_->isFunction(context);
}
bool UnaryOp::isPointing() const{
    return u_op_->isPointing();
}
