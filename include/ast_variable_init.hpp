#ifndef AST_VARIABLE_INIT_HPP
#define AST_VARIABLE_INIT_HPP

#include "ast_node.hpp"
#include "./ast/declarations/ast_direct_declarator.hpp"
#include "ast_identifier.hpp"

#include <string>

class VariableInit : public Node
{
public:
    VariableInit(Identifier *declarator, Node *initializer) : declarator_(declarator), initializer_(initializer) {};
    ~VariableInit(){};
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
private:
    Identifier *declarator_;
    Node *initializer_;
};


#endif
