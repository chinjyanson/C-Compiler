#ifndef AST_DECLARATOR_WITH_PARAMETERS_HPP
#define AST_DECLARATOR_WITH_PARAMETERS_HPP

#include "ast_node.hpp"
#include "ast_direct_declarator.hpp"

class DeclaratorWithParameters : public Node
{
private:
    DirectDeclarator *declarator_;
    Node *parameter_list_;
public:
    DeclaratorWithParameters(Node *declarator, Node *parameter_list) : declarator_(dynamic_cast<DirectDeclarator*>(declarator)), parameter_list_(parameter_list){};
    ~DeclaratorWithParameters()
    {
        delete declarator_;
        delete parameter_list_;
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    virtual std::string ReturnID();
};



#endif
