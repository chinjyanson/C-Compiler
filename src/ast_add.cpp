#include "ast_add.hpp"

void Add::EmitRISC(std::ostream &stream, Context &context, int destReg) const {

    int left_reg = context.getFreeRegister();
    int right_reg = context.getFreeRegister();

    left_->EmitRISC(stream, context, left_reg);
    right_->EmitRISC(stream, context, right_reg);
    stream << "add x" << destReg << ", x" << left_reg << ", x"<< right_reg << std::endl;

}

void Add::Print(std::ostream &stream) const {

}
