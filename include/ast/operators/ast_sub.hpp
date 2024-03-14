#ifndef AST_SUB_HPP
#define AST_SUB_HPP

#include "ast_node.hpp"

class Sub : public Node
{
    private:
        Node *left_;
        Node *right_;

    public:
        Sub(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~Sub() {
            delete left_;
            delete right_;
        }
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
};

#endif
