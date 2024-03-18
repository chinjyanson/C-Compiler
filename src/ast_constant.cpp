#include "ast_constant.hpp"

void IntConstant::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    stream << "li x" << destReg << ", " << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const
{
    stream << value_;
}

void FloatConstant::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    stream << "fli x" << destReg << ", " << value_ << std::endl;
}

void FloatConstant::Print(std::ostream &stream) const
{
    stream << value_;
}
