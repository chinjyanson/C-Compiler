#ifndef AST_POINTER_DECLARATOR_HPP
#define AST_POINTER_DECLARATOR_HPP

#include "ast_node.hpp"
#include "ast_identifier.hpp"

class PointerDeclarator : public Node
{
private:
    Node *pointer_;
    Node *identifier_;

public:
    PointerDeclarator(Node *pointer, Node *identifier) : pointer_(pointer), identifier_(identifier){};
    ~PointerDeclarator()
    {
        delete pointer_;
        delete identifier_;
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    virtual std::string ReturnID() const override;
    int getSize(Context &context) const override;
    void mapVars(Context &context) const override;
    void isFunction(Context &context) const override;
    bool isPointer(Context &context) const override;
};

#endif
