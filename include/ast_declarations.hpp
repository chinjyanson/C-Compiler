#ifndef AST_DECLARATIONS_HPP
#define AST_DECLARATIONS_HPP

#include "ast_node.hpp"
#include "ast_type_specifier.hpp"

class Declarations : public Node
{
public:
    Declarations(Node *dec_spec, Node *init_declarator_list) : dec_spec_(dynamic_cast<TypeSpecifier*>(dec_spec)), init_declarator_list_(dynamic_cast<NodeList*>(init_declarator_list)) {}
    ~Declarations(){}
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    void mapVars(Context &context) const override;

private:
    TypeSpecifier *dec_spec_;
    NodeList *init_declarator_list_;

};

#endif
