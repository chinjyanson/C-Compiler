#include "ast/declarations/ast_direct_declarator.hpp"

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    /* stream << ".globl ";
    identifier_->EmitRISC(stream, context, destReg);
    stream << std::endl;
    identifier_->EmitRISC(stream, context, destReg);
    stream << ":" << std::endl; */
}

void DirectDeclarator::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
}

std::string DirectDeclarator::ReturnID() const
{
    return identifier_->ReturnID();
}
