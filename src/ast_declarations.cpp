#include "ast_declarations.hpp"

void Declarations::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    dec_spec_->EmitRISC(stream, context, destReg); // this does nothing, it points to the typespec node
    init_declarator_list_->EmitRISC(stream, context, destReg); // this will call variable init
}

void Declarations::Print(std::ostream &stream) const {}

/* void Declarations::mapVariables(std::ostream &stream) {

} */
