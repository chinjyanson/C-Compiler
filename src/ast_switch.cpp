#include "ast_switch.hpp"
#include "ast_context.hpp"

void Switch::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    expr_->EmitRISC(stream, context, destReg);
    statement_->EmitRISC(stream, context, destReg);
}

void Switch::Print(std::ostream &stream) const
{
    stream << "switch(";
    expr_->Print(stream);
    stream << ")";
    statement_->Print(stream);
}

std::string Switch::ReturnID() const
{
    return "Switch";
}

void Switch::mapVars(Context &context) const
{
    expr_->mapVars(context);
    statement_->mapVars(context);
}

void Switch::isFunction(Context &context) const
{
    expr_->isFunction(context);
    statement_->isFunction(context);
}

int Switch::getSize(Context &context) const
{
    return expr_->getSize(context) + statement_->getSize(context);
}

