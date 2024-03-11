#ifndef AST_ADD_HPP
#define AST_ADD_HPP

#include "ast_node.hpp"

class AddOp : public Node
{
private:
    Node *left_;
    Node *right_;

public:
    AddOp(Node *left, Node *right) : left_(left), right_(right) {}

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
