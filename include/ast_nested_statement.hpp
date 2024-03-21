#ifndef AST_NESTED_STATEMENT_HPP
#define AST_NESTED_STATEMENT_HPP

#include "ast_node.hpp"

class NestStatement : public Node
{
private:
    Node *branch_;

public:
    NestStatement(Node *branch) : branch_(branch) {}
    ~NestStatement() {
        delete branch_;
    }

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
