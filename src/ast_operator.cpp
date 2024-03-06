#include "ast_operator.hpp"

void Add::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << "add ";
    left_->EmitRISC(stream, context);
    left_->EmitRISC(stream, context);
    right_->EmitRISC(stream, context);

}

void Add::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << "+";
    right_->Print(stream);
}
