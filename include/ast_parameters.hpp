#ifndef ast_ParamDeclaration_hpp
#define ast_ParamDeclaration_hpp

#include "ast_node.hpp"

class Parameter: public Node
{
public:
    Parameter(Node *dec_spec, Node *declarator) : param_type(dec_spec), param_name(declarator) {};

    ~Parameter();

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;

private:
    Node *param_type;
    Node *param_name;
};

#endif
