#ifndef AST_LT_OP_HPP
#define AST_LT_OP_HPP

#include "ast_node.hpp"

class LtOp : public Node
{
private:
    Node *left_;
    Node *right_;
public:
    LtOp(Node *left, Node *right) : left_(left), right_(right) {}
    virtual ~LtOp() {}
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
