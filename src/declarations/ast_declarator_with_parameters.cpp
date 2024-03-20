#include "ast/declarations/ast_declarator_with_parameters.hpp"

void DeclaratorWithParameters::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    stream << ".globl "; // probably check its global from context first
    declarator_->EmitRISC(stream, context, destReg); // this would probably just print the name
    stream << std::endl; // if this does more than that, cry
    declarator_->EmitRISC(stream, context, destReg);
    stream << ":" << std::endl; //function defn
    parameter_list_->EmitRISC(stream, context, destReg); // this should initliaise the params
}

void DeclaratorWithParameters::Print(std::ostream &stream) const
{
    declarator_->Print(stream);
    stream << "(";
    parameter_list_->Print(stream);
    stream << ")";
}

std::string DeclaratorWithParameters::ReturnID() const
{
    return declarator_->ReturnID();
}
