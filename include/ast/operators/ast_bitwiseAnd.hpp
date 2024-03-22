#ifndef AST_BITWISEAND_HPP
#define AST_BITWISEAND_HPP

#include "ast_node.hpp"

class BitwiseAnd : public Node
{
private:
    Node *left_;
    Node *right_;

public:
    BitwiseAnd(Node *left, Node *right) : left_(left), right_(right) {}
    virtual ~BitwiseAnd() {}
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    void isFunction(Context &context) const override;
};

#endif
