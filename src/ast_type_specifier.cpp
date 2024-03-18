#include "ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context, int destReg) const {
    std::string type = context.getVariableType(type_);
    if (type == "int"){
        stream << "li x" << destReg << ", 0" << std::endl;
    }
    if (type == "double"){
        stream << "fli x" << destReg << ", 0" << std::endl;
    }
    if (type == "float"){
        stream << "fli x" << destReg << ", 0" << std::endl;
    }
    if (type == "long"){
        stream << "li x" << destReg << ", 0" << std::endl;
    }
}

void TypeSpecifier::Print(std::ostream &stream) const
{
    stream << type_;
}

std::string TypeSpecifier::returnType() const{
    return type_;
}
