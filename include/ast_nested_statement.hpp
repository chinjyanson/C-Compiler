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
        if(branch_ != nullptr)
            delete branch_;
    }

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    void mapVars(Context &context) const override;
    void isFunction(Context &context) const override;
};

#endif
