#ifndef AST_SWITCH_HPP
#define AST_SWITCH_HPP


#include "ast_node.hpp"


class Switch: public Node
{
private:
    Node *expr_;
    Node *statement_;
public:
    Switch(Node *expr, Node *statement): expr_(expr), statement_(statement) {};
    ~Switch(){
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    virtual std::string ReturnID() const override;
    void mapVars(Context &context) const override;
    void isFunction(Context &context) const override;
    int getSize(Context &context) const override;
};
#endif