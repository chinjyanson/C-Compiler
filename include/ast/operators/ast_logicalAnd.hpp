#ifndef AST_LOGICALAND_HPP
#define AST_LOGICALAND_HPP

#include "ast_node.hpp"

class LogicAnd : public Node
{
    private:
        Node *left_;
        Node *right_;
    public:
        LogicAnd(Node *left, Node *right) : left_(left), right_(right) {}
        virtual ~LogicAnd() {}
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
        void isFunction(Context &context) const override;
};

#endif
