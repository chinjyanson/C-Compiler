#include "ast_direct_declarator.hpp"

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    identifier_->EmitRISC(stream, context);
    stream << ":" << std::endl;
    parameter_list->EmitRISC(stream, context);
}

void DirectDeclarator::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
    parameter_list->Print(stream);
}
