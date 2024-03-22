#include "ast/multi/ast_nested_statement.hpp"

void NestStatement::EmitRISC(std::ostream &stream, Context &context, int destReg) const {
    bool was_function = context.is_function;
    branch_->EmitRISC(stream, context, destReg);
    context.is_function = was_function;
}

void NestStatement::Print(std::ostream &stream) const {
    stream << "{";
    branch_->Print(stream);
    stream << "}";
}

void NestStatement::mapVars(Context &context) const{
    branch_->mapVars(context);
}

void NestStatement::isFunction(Context &context) const{
    branch_->isFunction(context);
}
