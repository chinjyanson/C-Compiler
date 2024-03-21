#ifndef AST_TYPE_SPECIFIER
#define AST_TYPE_SPECIFIER

#include "ast_node.hpp"

class TypeSpecifier : public Node
{
private:
    std::string type_;

public:
    TypeSpecifier(std::string type) : type_(type){};
    ~TypeSpecifier(){
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    std::string returnType() const override;
    int getSize() const override;
};

#endif
