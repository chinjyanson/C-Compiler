#include "ast_pointer_declarator.hpp"

void PointerDeclarator::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{


}

void PointerDeclarator::Print(std::ostream &stream) const {
}

int PointerDeclarator::getSize(Context &context) const{

}
void PointerDeclarator::mapVars(Context &context) const{

}
void PointerDeclarator::isFunction(Context &context) const{

}
void PointerDeclarator::isPointer(Context &context) const{

}
std::string PointerDeclarator::ReturnID() const{
    return identifier_->ReturnID();
}
