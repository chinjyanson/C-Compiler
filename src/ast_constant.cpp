#include "ast_constant.hpp"

void IntConstant::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    stream << "li x" << destReg << ", " << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const
{
    stream << value_;
}

int IntConstant::getSize(Context &context) const {
    return 4;
}

void FloatConstant::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    stream << "fli x" << destReg << ", " << value_ << std::endl;
}

void FloatConstant::Print(std::ostream &stream) const
{
    stream << value_;
}

int FloatConstant::getSize(Context &context) const {
    return 8;
}
