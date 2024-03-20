#include "ast_argument.hpp"

void Argument::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    int arg_size = arg_->getSize();
    int arg_reg = context.findParamReg();
    arg_->EmitRISC(stream, context, arg_reg);
    context.mem_offset -= arg_size;
    stream << "sw x" << arg_reg << ", " << context.mem_offset << "(s0)" << std::endl;
    context.freeRegister(arg_reg);
}

void Argument::Print(std::ostream &stream) const{
    arg_->Print(stream);
};

int Argument::getSize() const{
    return arg_->getSize();
}
