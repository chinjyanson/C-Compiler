#include "ast_multiline.hpp"

void Multiline::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    declaration_list_->EmitRISC(stream, context, destReg);
    statement_list_->EmitRISC(stream, context, destReg);
}

void Multiline::Print(std::ostream &stream) const
{
}
