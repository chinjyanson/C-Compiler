#include "ast/operators/ast_unary_sign.hpp"

void UnarySign::EmitRISC(std::ostream &stream, Context &context, int destReg) const {
    if(u_op_=="-"){
        stream << "neg x" << destReg << ", x" << destReg << std::endl;
    }
    else if (u_op_ == "*"){
        stream << "lw x" << destReg << ", 0(x"  << destReg << ")" << std::endl;
    }
}

void UnarySign::Print(std::ostream &stream) const {
}

std::string UnarySign::ReturnID() const{
    return u_op_;
}

bool UnarySign::isPointing() const{
    if (u_op_ == "*"){
        return true;
    }
    else {
        return false;
    }
}
