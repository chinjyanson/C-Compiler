#ifndef AST_BITWISEXOR_HPP
#define AST_BITWISEXOR_HPP

#include "ast_node.hpp"

class BitwiseXor : public Node
{
    private:
        Node *left_;
        Node *right_;
    public:
        BitwiseXor(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~BitwiseXor() {
            delete left_;
            delete right_;
        }
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
};

#endif 