#ifndef AST_MULTIPLY_OP_HPP
#define AST_MULTIPLY_OP_HPP

#include "ast_node.hpp"

class MultiplyOp : public Node
{
private:
    Node *left_;
    Node *right_;

public:
    MultiplyOp(Node *left, Node *right) : left_(left), right_(right) {}
    virtual ~MultiplyOp() {}
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    void isFunction(Context &context) const override;
};

#endif
