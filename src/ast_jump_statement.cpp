#include "ast_jump_statement.hpp"

void ReturnStatement::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    if (expression_ != nullptr)
    {
        stream << "not null for sure" << std::endl;
        expression_->EmitRISC(stream, context, destReg);
        stream << "done" << std::endl;
    }
    stream << "ret" << std::endl;
}

void ReturnStatement::Print(std::ostream &stream) const
{
    stream << "return";
    if (expression_ != nullptr)
    {
        stream << " ";
        expression_->Print(stream);
    }
    stream << ";" << std::endl;
}
