#include "ast_array.hpp"

void Array::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    loadAddress(stream, context, destReg);
    stream << "lw x" << destReg << ", 0(x" << destReg << ")" << std::endl;
}

void Array::Print(std::ostream &stream) const {
}

int Array::getSize(Context &context) const{

}
void Array::mapVars(Context &context) const{

}
std::string Array::ReturnID() const{
    return declarator_->ReturnID();
}
int Array::getnElements() const{
    return constant_->getValue();
}

void Array::loadAddress(std::ostream &stream, Context &context, int destReg) const{
    int dec_reg = context.getFreeRegister();
    int cons_reg = context.getFreeRegister();
    int temp_reg = context.getFreeRegister();
    declarator_->EmitRISC(stream, context, dec_reg);
    constant_->EmitRISC(stream, context, cons_reg);

    // this doesn't support 1[p] where p is a pointer

    // turning the lack of error handling into a feature hehe
    int array_word_size = context.checkSize(context.getVariableType(declarator_->ReturnID()));
    stream << "li x" << temp_reg << ", " << array_word_size << std::endl;
    stream << "mul x" << cons_reg << ", x" << cons_reg << ", x" << temp_reg << std::endl;
    stream << "add x" << destReg << ", x" << dec_reg << ", x" << cons_reg  << std::endl;
    context.freeRegister(dec_reg);
    context.freeRegister(cons_reg);
    context.freeRegister(temp_reg);
}
