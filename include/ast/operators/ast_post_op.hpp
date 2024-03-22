#ifndef AST_POST_OP_HPP
#define AST_POST_OP_HPP

#include "ast_node.hpp"
#include "ast/calls/ast_variable_call.hpp"

#include <string>

class PostOp : public Node
{
    private:
        VariableCall *expr_;
        std::string op_;

    public:
        PostOp(Node *expr, std::string op) : op_(op), expr_(dynamic_cast<VariableCall*>(expr)) {}
        virtual ~PostOp() {}
        virtual void EmitRISC(std::ostream &stream, Context &context, int destReg) const override;
        virtual void Print(std::ostream &stream) const override;
        void isFunction(Context &context) const override;
};

#endif
