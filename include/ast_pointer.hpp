#ifndef AST_POINTER_HPP
#define AST_POINTER_HPP

#include "ast_node.hpp"

class Pointer: public Node
{
private:
    std::string star_;
public:
    Pointer(std::string star) : star_(star) {};
    ~Pointer(){};
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    virtual std::string ReturnID() const override;
    int getSize(Context &context) const override;
    void mapVars(Context &context) const override;
    void isFunction(Context &context) const override;
    void isPointer(Context &context) const override;
};

#endif
