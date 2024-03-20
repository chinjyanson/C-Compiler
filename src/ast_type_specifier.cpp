#include "ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context, int destReg) const {
}

void TypeSpecifier::Print(std::ostream &stream) const
{
    stream << type_;
}

std::string TypeSpecifier::returnType() const{
    return type_;
}

int TypeSpecifier::getSize() const{
    if(type_=="char"){
        return 1;
    }
    else if(type_=="float"){
        return 8;
    }
    else if(type_=="double"){
        return 4;
    }
    else{
        return 4;
    }
}
