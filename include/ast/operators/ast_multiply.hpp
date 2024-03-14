#ifndef AST_DIVIDE_HPP
#define AST_DIVIDE_HPP

#include "ast_node.hpp"

class Multiply : public Node
{
    private:
        Node *left_;
        Node *right_;

    public:
        Multiply(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~Multiply() {
            delete left_;
            delete right_;
        }
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
};

#endif