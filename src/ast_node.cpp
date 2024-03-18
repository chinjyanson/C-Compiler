#include "ast_node.hpp"

Node::~Node()
{
    for (auto branch : branches_)
    {
        delete branch;
    }
}

void Node::Print(std::ostream &stream) const
{
    stream << "you should be here";
}

std::string Node::ReturnID() const{
    return "you should not be here, this is just a node";
}

void NodeList::PushBack(Node *item)
{
    nodes_.push_back(item);
}

void NodeList::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->EmitRISC(stream, context, destReg);
    }
}

void NodeList::Print(std::ostream &stream) const
{
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->Print(stream);
    }
}

std::vector<std::string> NodeList::returnIDs() const{
    std::vector<std::string> id_list;
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        id_list.push_back(node->ReturnID()); // dynamic cast here?
    }
    return id_list;
}
