#ifndef AST_PARAMETERS_HPP
#define AST_PARAMETERS_HPP

#include "ast_node.hpp"
#include <vector>

class Parameter : public Node {
private:
    Node* declaration_specifiers_;
    Node* declarator_;

public:
    Parameter(Node* declaration_specifiers, Node* declarator) :
        declaration_specifiers_(declaration_specifiers), declarator_(declarator) {}

    ~Parameter() {
        delete declaration_specifiers_;
        delete declarator_;
    }


    void EmitRISC(std::ostream& stream, Context& context) const override;
    void Print(std::ostream& stream) const override;
};

#endif
