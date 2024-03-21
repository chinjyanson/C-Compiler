#ifndef AST_VARIABLE_INIT_HPP
#define AST_VARIABLE_INIT_HPP

#include "ast_node.hpp"
#include "./ast/declarations/ast_direct_declarator.hpp"
#include "ast_identifier.hpp"

#include <string>

class VariableInit : public Node
{
public:
    VariableInit(Node *declarator, Node *initializer) : declarator_(dynamic_cast<Identifier*>(declarator)), initializer_(initializer) {};
    ~VariableInit(){
        delete declarator_;
        delete initializer_;
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    std::string ReturnID() const override;
private:
    Identifier *declarator_;
    Node *initializer_;
};


#endif
