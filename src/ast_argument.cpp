#include "ast_argument.hpp"

void Argument::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    int arg_reg = context.findParamReg();
    arg_->EmitRISC(stream, context, arg_reg);
}

void Argument::Print(std::ostream &stream) const{
    arg_->Print(stream);
};

int Argument::getSize() const{
    return arg_->getSize();
}
