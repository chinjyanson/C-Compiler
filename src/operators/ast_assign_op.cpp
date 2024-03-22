#include "ast/operators/ast_assign_op.hpp"

void AssignOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int expr_reg = context.getFreeRegister();
    int is_array = context.checkArraySize(var_->ReturnID());

    if(is_array!=-1){
        var_->loadAddress(stream, context, destReg);
        stream << "sw x" << expr_reg << ", 0(x" << destReg << ")" << std::endl;
    }
    else{
        var_->EmitRISC(stream, context, destReg);
        expr_->EmitRISC(stream, context, expr_reg);
        stream << "mv x" << destReg << ", x" << expr_reg << std::endl;
        context.freeRegister(expr_reg);
        var_->UpdateVar(stream, context, destReg);
    }


}

void AssignOp::Print(std::ostream &stream) const {

}

void AssignOp::isFunction(Context &context) const{
    var_->isFunction(context);
    expr_->isFunction(context);
}

