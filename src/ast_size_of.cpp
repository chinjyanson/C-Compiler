#include "ast_size_of.hpp"

void SizeOf::Print(std::ostream &stream) const
{
    stream << "sizeof(";
    type_->Print(stream);
    stream << ")";
}

void SizeOf::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    stream << "li " << destReg << ", x" << 0 << std::endl;
}

int SizeOf::getSize() const
{
    return 4;
}

