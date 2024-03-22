#include "ast/pointers/ast_pointer.hpp"

void Pointer::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{


}

void Pointer::Print(std::ostream &stream) const {
}

int Pointer::getSize(Context &context) const{

}
void Pointer::mapVars(Context &context) const{

}
void Pointer::isFunction(Context &context) const{

}
bool Pointer::isPointer(Context &context) const{
    return true;
}
std::string Pointer::ReturnID() const{
    return "*";
}
