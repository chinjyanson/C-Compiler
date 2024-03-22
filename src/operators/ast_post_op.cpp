#include "ast/operators/ast_post_op.hpp"

void PostOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    bool is_p = expr_->isPointer(context);

    expr_->EmitRISC(stream, context, destReg);
    if(op_=="--"){
        if(is_p){
            int size = expr_->getSize(context);
            stream << "addi x" << destReg << ", x" << destReg << ", -" << size << std::endl;
        }
        else{
            stream << "addi x" << destReg << ", x" << destReg << ", -1" << std::endl;
        }
        expr_->UpdateVar(stream, context, destReg);
    }
    else if (op_ == "++"){
        if(is_p){
            int size = expr_->getSize(context);
            stream << "addi x" << destReg << ", x" << destReg << ", " << size << std::endl;
        }
        else{
            stream << "addi x" << destReg << ", x" << destReg << ", 1" << std::endl;
        }
        expr_->UpdateVar(stream, context, destReg);
    }
}

void PostOp::Print(std::ostream &stream) const {
}
void PostOp::isFunction(Context &context) const{
    expr_->isFunction(context);
}
