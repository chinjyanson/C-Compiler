#ifndef AST_DIRECT_DECLARATOR_HPP
#define AST_DIRECT_DECLARATOR_HPP

#include "ast_node.hpp"

class DirectDeclarator : public Node
{
private:
    Node *identifier_;
    NodeList *parameter_list;

public:
    DirectDeclarator(Node* identifier) : identifier_(identifier), parameter_list(nullptr) {}
    DirectDeclarator(Node* identifier, NodeList* parameter_list) : identifier_(identifier), parameter_list(parameter_list) {}
    ~DirectDeclarator()
    {
        delete identifier_;
        delete parameter_list;
    };
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
};

#endif
