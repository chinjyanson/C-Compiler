#ifndef AST_FOR_HPP
#define AST_FOR_HPP

#include "ast_node.hpp"

class ForLoop : public Node
{
private:
    Node *init_;
    Node *condition_;
    Node *increment_;
    Node *statement_;
public:
    ForLoop(Node *init, Node *condition, Node *increment, Node *statement) : init_(init), condition_(condition), increment_(increment), statement_(statement) {}
    ~ForLoop() {
        delete init_;
        delete condition_;
        delete increment_;
        delete statement_;
    }

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    void mapVars(Context &context) const override;
    void isFunction(Context &context) const override;
};

#endif
