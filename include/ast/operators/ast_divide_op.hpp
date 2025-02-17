#ifndef AST_DIVIDE_OP_HPP
#define AST_DIVIDE_OP_HPP

#include "ast_node.hpp"

class DivideOp : public Node
{
    private:
        Node *left_;
        Node *right_;

    public:
        DivideOp(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~DivideOp() {}
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
        void isFunction(Context &context) const override;
        int getValue() const override;
};

#endif
