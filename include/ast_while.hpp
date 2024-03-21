#ifndef AST_WHILE_LOOP_HPP
#define AST_WHILE_LOOP_HPP

#include "ast_node.hpp"

class WhileLoop : public Node
{
private:
    Node *condition_;
    Node *statement1_;
    bool is_do_;

public:
    WhileLoop(Node *condition, Node *statement1, bool is_do) : condition_(condition), statement1_(statement1), is_do_(is_do){}
    ~WhileLoop() {
        delete condition_;
        delete statement1_;
    }

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    void isFunction(Context &context) const override;
};

#endif
