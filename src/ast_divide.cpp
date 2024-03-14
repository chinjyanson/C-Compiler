#include "./ast/operators/ast_divide.hpp"

void Divide::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);
    stream << "div x" << destReg << ", x" << left_reg << ", x"<< right_reg << std::endl;

}

void Divide::Print(std::ostream &stream) const {
    left_->Print(stream);
    stream << " / ";
    right_->Print(stream);
}
