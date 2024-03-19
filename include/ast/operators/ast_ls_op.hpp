#ifndef AST_LS_OP_HPP
#define AST_LS_OP_HPP

#include "ast_node.hpp"

class LsOp : public Node
{
private:
    Node *left_;
    Node *right_;
public:
    LsOp(Node *left, Node *right) : left_(left), right_(right) {}
    virtual ~LsOp() {
        delete left_;
        delete right_;
    }
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
