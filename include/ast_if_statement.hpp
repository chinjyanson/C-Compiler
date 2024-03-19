#ifndef AST_IF_STATEMENT_HPP
#define AST_IF_STATEMENT_HPP

#include "ast_node.hpp"

class IfStatement : public Node
{
private:
    Node *condition_;
    Node *statement1_;
    Node *statement0_;

public:
    IfStatement(Node *condition, Node *statement1, Node *statement0) : condition_(condition), statement1_(statement1), statement0_(statement0) {}
    ~IfStatement()
    {
        delete condition_;
        delete statement1_;
        delete statement0_;
    };

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
