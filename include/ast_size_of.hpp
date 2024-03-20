#ifndef ast_size_of_hpp
#define ast_size_of_hpp

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include "ast_node.hpp" 

class SizeOf : public Node
{
private:
    Node* type_;
public:
    SizeOf(Node *type): type_(type) {};
    virtual ~SizeOf(){

    };

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    int getSize() const;
};


#endif 