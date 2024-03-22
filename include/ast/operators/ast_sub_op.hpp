#ifndef AST_SUB_OP_HPP
#define AST_SUB_OP_HPP

#include "ast_node.hpp"

class SubOp : public Node
{
    private:
        Node *left_;
        Node *right_;

    public:
        SubOp(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~SubOp() {}
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
        void isFunction(Context &context) const override;
        int getValue() const override;
};

#endif
