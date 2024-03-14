#ifndef AST_ADD_HPP
#define AST_ADD_HPP

#include "ast_node.hpp"

class Add : public Node
{
private:
    Node *left_;
    Node *right_;

public:
    Add(Node *left, Node *right) : left_(left), right_(right) {}
    virtual ~Add() {
        delete left_;
        delete right_;
    }
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
