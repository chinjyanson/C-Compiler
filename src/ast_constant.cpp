#include "ast_constant.hpp"

void IntConstant::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    stream << "li "<< destReg << "," << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const
{
    stream << value_;
}
