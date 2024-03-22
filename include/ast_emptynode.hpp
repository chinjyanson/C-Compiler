#ifndef AST_EMPTYNODE_HPP
#define AST_EMPTYNODE_HPP

#include "ast_node.hpp"

class EmptyNode : public Node
{
public:
    EmptyNode();

    virtual ~EmptyNode();

    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;

    virtual void Print(std::ostream &stream) const override;

    virtual int getSize(Context &context) const override;

    virtual bool isPointer(Context &context) const override;


};

#endif