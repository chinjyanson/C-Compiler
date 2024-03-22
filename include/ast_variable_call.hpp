#ifndef AST_VARIABLE_CALL_HPP
#define AST_VARIABLE_CALL_HPP

#include "ast_node.hpp"

#include <string>

class VariableCall : public Node
{
public:
    VariableCall(std::string identifier) : identifier_(identifier) {};
    ~VariableCall(){};
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    virtual void UpdateVar(std::ostream &stream, Context &context, int destReg) const override;
    std::string ReturnID() const override;
    int getSize(Context &context) const override;
private:
    std::string identifier_;
};


#endif
