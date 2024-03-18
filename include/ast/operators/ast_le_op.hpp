#ifndef AST_LE_OP_HPP
#define AST_LE_OP_HPP

#include "ast_node.hpp"

class LeOp : public Node
{
private: 
    Node *left_;
    Node *right_;   
public:
    LeOp(Node *left, Node *right) : left_(left), right_(right) {}
    virtual ~LeOp() {
        delete left_;
        delete right_;
    }
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif 