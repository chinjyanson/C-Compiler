#ifndef AST_DECLARATOR_WITH_PARAMETERS_HPP
#define AST_DECLARATOR_WITH_PARAMETERS_HPP

#include "ast_node.hpp"

#include <vector>
#include <string>
#include <map>

class DeclaratorWithParameters : public Node
{
private:
    Node *declarator_;
    NodeList *parameter_list_;
public:
    DeclaratorWithParameters(Node *declarator, Node *parameter_list) : declarator_(declarator), parameter_list_(dynamic_cast<NodeList*>(parameter_list)){};
    ~DeclaratorWithParameters()
    {
        delete declarator_;
        delete parameter_list_;
    };
    void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
    void Print(std::ostream &stream) const override;
    virtual std::string ReturnID() const override;
    void mapParams(Context &context) const override;
};



#endif
