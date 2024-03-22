#include "ast_emptynode.hpp"

EmptyNode::EmptyNode() {}

EmptyNode::~EmptyNode() {}

void EmptyNode::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{}

int EmptyNode::getSize(Context &context) const{
    return -1;
}

void EmptyNode::Print(std::ostream &stream) const
{
    stream << "EmptyNode";
}

bool EmptyNode::isPointer(Context &context) const
{
    return false;
}