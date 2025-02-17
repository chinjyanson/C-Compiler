#ifndef AST_BITWISEOR_HPP
#define AST_BITWISEOR_HPP

#include "ast_node.hpp"

class BitwiseOr : public Node
{
    private:
        Node *left_;
        Node *right_;
    public:
        BitwiseOr(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~BitwiseOr() {}
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
        void isFunction(Context &context) const override;
        int getValue() const override;
};

#endif
