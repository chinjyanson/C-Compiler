#ifndef AST_ARRAY_HPP
#define AST_ARRAY_HPP

#include "ast_node.hpp"

class Array: public Node
{
private:
    Node *declarator_;
    Node *constant_;
public:
    Array(Node *declarator, Node *constant) : declarator_(declarator), constant_(constant) {};
    ~Array(){
        delete declarator_;
        delete constant_;
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    virtual std::string ReturnID() const override;
    int getSize(Context &context) const override;
    void mapVars(Context &context) const override;
    int getnElements() const override;
    virtual void loadAddress(std::ostream &stream, Context &context, int destReg) const override;
};

#endif
