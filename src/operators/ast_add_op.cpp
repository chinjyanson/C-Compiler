#include "ast/operators/ast_add_op.hpp"

void AddOp::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    bool left_p = left_->isPointer(context);
    bool right_p = right_->isPointer(context);

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);

    if(left_p){
        int size = left_->getSize(context);
        int temp_reg = context.getFreeRegister();
        stream << "li x" << temp_reg << ", " << size << std::endl;
        stream << "mul x" << right_reg << ", x" << right_reg << ", x" << temp_reg << std::endl;
        context.freeRegister(temp_reg);
    }
    else if(right_p){
        int size = right_->getSize(context);
        int temp_reg = context.getFreeRegister();
        stream << "li x" << temp_reg << ", " << size << std::endl;
        stream << "mul x" << left_reg << ", x" << left_reg << ", x" << temp_reg << std::endl;
        context.freeRegister(temp_reg);
    }

    stream << "add x" << destReg << ", x" << left_reg << ", x"<< right_reg << std::endl;
    context.freeRegister(left_reg);
    context.freeRegister(right_reg);

}

void AddOp::Print(std::ostream &stream) const {
    left_->Print(stream);
    stream << " + ";
    right_->Print(stream);
}

void AddOp::isFunction(Context &context) const{
    left_->isFunction(context);
    right_->isFunction(context);
}

int AddOp::getValue() const{
    return left_->getValue() + right_->getValue();
}
