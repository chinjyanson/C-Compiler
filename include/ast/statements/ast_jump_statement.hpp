#ifndef AST_JUMP_STATEMENT_HPP
#define AST_JUMP_STATEMENT_HPP

#include "ast_node.hpp"

class ReturnStatement : public Node
{
private:
    Node *expression_;

public:
    ReturnStatement(Node *expression) : expression_(expression) {}
    ~ReturnStatement()
    {
        if (expression_ != nullptr){
            delete expression_;
        }
    };

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    void isFunction(Context &context) const override;
};

#endif
