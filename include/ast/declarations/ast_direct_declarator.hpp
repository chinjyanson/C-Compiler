#ifndef AST_DIRECT_DECLARATOR_HPP
#define AST_DIRECT_DECLARATOR_HPP

#include "ast_node.hpp"
#include "ast_identifier.hpp"

class DirectDeclarator : public Node
{
private:
    Identifier *identifier_;

public:
    DirectDeclarator(Node *identifier) : identifier_(dynamic_cast<Identifier*>(identifier)){};
    ~DirectDeclarator()
    {
        delete identifier_;
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;

    virtual std::string ReturnID();
};

#endif
