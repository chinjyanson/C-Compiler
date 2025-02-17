#ifndef AST_PARAM_DECLARATION_HPP
#define AST_PARAM_DECLARATION_HPP

#include "ast_node.hpp"
#include "ast_type_specifier.hpp"

#include <string>

class Parameter : public Node
{
public:
    Parameter(Node *dec_spec, Node *declarator) : dec_spec_(dynamic_cast<TypeSpecifier*>(dec_spec)), declarator_(declarator) {}
    ~Parameter(){
        delete dec_spec_;
        delete declarator_;
    }
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    std::string ReturnID() const override;
    std::string returnType() const override;
    bool isPointer(Context &context) const override;

private:
    TypeSpecifier *dec_spec_;
    Node *declarator_;

};

#endif
