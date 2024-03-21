#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iostream>
#include <vector>

#include "ast_context.hpp"

class Node
{
protected:
    std::vector<Node *> branches_;

public:
    Node(){};
    virtual ~Node();
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const = 0;
    virtual void Print(std::ostream &stream) const = 0;
    virtual std::string ReturnID() const;
    virtual std::string returnType() const;
    virtual int getSize(Context &context) const;
    virtual void mapParams(Context &context) const;
    virtual void mapVars(Context &context) const;
    virtual void isFunction(Context &context) const;
};

// Represents a list of nodes.
class NodeList : public Node
{
private:
    std::vector<Node *> nodes_;

public:
    NodeList(Node *first_node) : nodes_({first_node}) {}

    ~NodeList()
    {
        for (auto node : nodes_)
        {
            delete node;
        }
    }

    void PushBack(Node *item);
    virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    virtual void EmitBackwards(std::ostream &stream, Context &context, int destReg) const;
    virtual void Print(std::ostream &stream) const override;
    virtual std::vector<std::string> returnIDs() const;
    virtual std::vector<std::string> returnTypes() const;
    virtual void mapVars(Context &context) const override;
    virtual void mapParams(Context &context) const override;
    virtual void isFunction(Context &context) const override;

};

#endif
