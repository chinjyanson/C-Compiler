#include "ast_parameters.hpp"

void Parameter::EmitRISC(std::ostream& stream, Context& context) const {
    declarator_->EmitRISC(stream, context);
}

void Parameter::Print(std::ostream& stream) const {
    declaration_specifiers_->Print(stream);
    declarator_->Print(stream);
}
