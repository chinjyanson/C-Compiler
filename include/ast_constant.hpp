#ifndef AST_CONSTANT_HPP
#define AST_CONSTANT_HPP

#include "ast_node.hpp"

class IntConstant : public Node
{
    private:
        int value_;

    public:
        IntConstant(int value) : value_(value) {}

        void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        void Print(std::ostream &stream) const override;
        int getSize(Context &context) const override;
        int getValue() const override;
};


class FloatConstant : public Node
{
private:
    float value_;
public:
    FloatConstant(float value) : value_(value) {}

    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    int getSize(Context &context) const override;
};

#endif
