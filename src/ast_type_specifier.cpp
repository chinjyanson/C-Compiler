#include "ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context, int destReg) const {
    std::string type = context.getType(type_);

}

void TypeSpecifier::Print(std::ostream &stream) const
{
    stream << type_;
}

std::string TypeSpecifier::returnType() const{
    return type_;
}
