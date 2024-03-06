#ifndef AST_OPERATOR_HPP
#define AST_OPERATOR_HPP

#include "ast_node.hpp"

class Operator : public Node
{
protected:
    Node *left_;
    Node *right_;

public:
    Operator(Node *left, Node *right) : left_(left), right_(right) {};
    ~Operator(){};
};

class Add : public Operator
{
public:
    Add(Node *left, Node *right) : Operator(left, right) {};
    ~Add(){};
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
};

#endif
