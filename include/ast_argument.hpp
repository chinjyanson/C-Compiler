#ifndef AST_ARGUMENT_HPP
#define AST_ARGUMENT_HPP

#include "ast_node.hpp"

class Argument : public Node
{
public:
    Argument(Node *arg) : arg_(arg) {}
    ~Argument(){}
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    int getSize() const override;

private:
    Node *arg_;
};

#endif
