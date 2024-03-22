#ifndef AST_FUNCTION_CALL_HPP
#define AST_FUNCTION_CALL_HPP

#include "ast_node.hpp"

#include <string>
#include <map>

class FunctionCall : public Node
{
public:
    FunctionCall(Node *name, Node *args) : name_(name), args_(dynamic_cast<NodeList*>(args)) {};
    ~FunctionCall(){
        delete name_;
        if(args_ != nullptr){
            delete args_;
        }
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    int getSize(Context &context) const override;
    void isFunction(Context &context) const override;
private:
    Node *name_;
    NodeList *args_;
};


#endif
