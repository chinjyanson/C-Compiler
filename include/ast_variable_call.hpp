#ifndef AST_VARIABLE_DECL_HPP
#define AST_VARIABLE_DECL_HPP

#include "ast_node.hpp"
#include "./ast/declarations/ast_direct_declarator.hpp"
#include "ast_identifier.hpp"

#include <string>

class VariableCall : public Node
{
public:
    VariableCall(std::string identifier) : identifier_(identifier) {};
    ~VariableCall(){};
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
private:
    std::string identifier_;
};


#endif
