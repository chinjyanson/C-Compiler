#ifndef AST_UNARY_SIGN_HPP
#define AST_UNARY_SIGN_HPP

#include "ast_node.hpp"

#include <string>

class UnarySign : public Node
{
private:
    std::string u_op_;

public:
    UnarySign(std::string u_op) : u_op_(u_op){}
    virtual ~UnarySign() {}
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
