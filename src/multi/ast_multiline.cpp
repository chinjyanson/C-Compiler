#include "ast/multi/ast_multiline.hpp"

void Multiline::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    declaration_list_->EmitRISC(stream, context, destReg);
    statement_list_->EmitRISC(stream, context, destReg);
}

void Multiline::Print(std::ostream &stream) const
{
    declaration_list_->Print(stream);
    statement_list_->Print(stream);
}

void Multiline::mapVars(Context &context) const{
    statement_list_->mapVars(context);
}

void Multiline::isFunction(Context &context) const{
    statement_list_->isFunction(context);
}
