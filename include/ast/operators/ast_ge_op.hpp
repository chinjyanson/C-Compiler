#ifndef AST_GE_OP_HPP
#define AST_GE_OP_HPP

#include "ast_node.hpp"

class GeOp : public Node
{
    private:
        Node *left_;
        Node *right_;
    public:
        GeOp(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~GeOp() {}
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
};

#endif
