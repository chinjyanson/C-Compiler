#ifndef AST_ASSIGN_OP_HPP
#define AST_ASSIGN_OP_HPP

#include "ast_node.hpp"
#include "ast_variable_call.hpp"

class AssignOp : public Node
{
private:
    Node *var_;
    Node *expr_;

public:
    AssignOp(Node *var, Node *expr) : var_(var), expr_(expr) {}
    ~AssignOp() {
        delete var_;
        delete expr_;
    }
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    void isFunction(Context &context) const override;
};

#endif
