#ifndef AST_NE_OP_HPP
#define AST_NE_OP_HPP

#include "ast_node.hpp"

class NeOp : public Node
{
    private:
        Node *left_;
        Node *right_;
    public:
        NeOp(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~NeOp() {}
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
        void isFunction(Context &context) const override;
};

#endif
