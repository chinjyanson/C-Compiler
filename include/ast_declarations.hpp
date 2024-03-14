#ifndef AST_DECLARATIONS_HPP
#define AST_DECLARATIONS_HPP

#include "ast_node.hpp"

class Declarations : public Node
{
public:
    Declarations(Node *dec_spec, Node *init_declarator_list) : dec_spec_(dec_spec), init_declarator_list_(init_declarator_list) {}
    ~Declarations(){}
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    //void mapVariables(Context &context){}

private:
    Node *dec_spec_;
    Node *init_declarator_list_;

};

#endif
