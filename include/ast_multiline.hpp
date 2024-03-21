#ifndef AST_MULTILINE_HPP
#define AST_MULTILINE_HPP

#include "ast_node.hpp"

class Multiline : public Node
{
public:
    Multiline(Node *declaration_list, Node *statement_list) : declaration_list_(declaration_list), statement_list_(statement_list) {};
    ~Multiline(){};
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    void mapVars(Context &context) const override;
    void isFunction(Context &context) const override;
private:
    Node *declaration_list_;
    Node *statement_list_;
};


#endif
