#ifndef AST_LOGICALOR_HPP
#define AST_LOGICALOR_HPP

#include "ast_node.hpp"

class LogicOr : public Node
{
    private:
        Node *left_;
        Node *right_;
    public:
        LogicOr(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~LogicOr() {
            delete left_;
            delete right_;
        }
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
};

#endif
