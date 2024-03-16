#include "./ast/declarations/ast_declarator_with_parameters.hpp"

void DeclaratorWithParameters::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    declarator_->EmitRISC(stream, context, destReg);
    parameter_list_->EmitRISC(stream, context, destReg);
}

void DeclaratorWithParameters::Print(std::ostream &stream) const
{
    declarator_->Print(stream);
    stream << "(";
    parameter_list_->Print(stream);
    stream << ")";
}

std::string DeclaratorWithParameters::ReturnID()
{
    return declarator_->ReturnID();
}
