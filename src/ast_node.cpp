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
std::string Node::returnType() const{
    return "you should not be here, this is just a node";
}

int Node::getSize(Context &context) const{
    return -1;
}

void Node::mapParams(Context &context) const{

}
void Node::mapVars(Context &context) const{

}
void Node::isFunction(Context &context) const{

}
bool Node::isPointer(Context &context) const{
    return false;
}
bool Node::isPointing() const{
    return false;
}
void Node::UpdateVar(std::ostream &stream, Context &context, int destReg) const{

}
void Node::loadAddress(std::ostream &stream, Context &context,int destReg) const{

}
int Node::getnElements() const{
    return -1;
}
int Node::getValue() const{
    return -1;
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

void NodeList::EmitBackwards(std::ostream &stream, Context &context, int destReg) const{
    for (auto node = nodes_.rbegin(); node != nodes_.rend(); node++){
        if (*node == nullptr)
        {
            continue;
        }
        (*node)->EmitRISC(stream, context, destReg);
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

std::vector<std::string> NodeList::returnTypes() const{
    std::vector<std::string> type_list;
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        type_list.push_back(node->returnType());
    }
    return type_list;
}

void NodeList::mapParams(Context &context) const{
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->mapParams(context);
    }
}

void NodeList::mapVars(Context &context) const{
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->mapVars(context);
    }
}

void NodeList::isFunction(Context &context) const{
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->isFunction(context);
    }
}
