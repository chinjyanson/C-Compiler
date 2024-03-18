#ifndef AST_COMPOUND_STATEMENT_HPP
#define AST_COMPOUND_STATEMENT_HPP

#include "ast_node.hpp"

class CompStatement : public Node
{
private:
    Node *branch_;

public:
    CompStatement(Node *branch) : branch_(branch) {}
    ~CompStatement() {}

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
