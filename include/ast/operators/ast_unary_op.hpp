#ifndef AST_UNARY_OP_HPP
#define AST_UNARY_OP_HPP

#include "ast_node.hpp"

#include <string>

class UnaryOp : public Node
{
private:
    Node *u_op_;
    Node *expr_;

public:
    UnaryOp(Node *u_op, Node *expr) : u_op_(u_op), expr_(expr) {}
    virtual ~UnaryOp() {}
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    void isFunction(Context &context) const override;
    bool isPointing() const override;
};

#endif
