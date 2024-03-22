#include "ast/declarations/ast_declarator_with_parameters.hpp"

void DeclaratorWithParameters::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    /* stream << ".globl ";
    declarator_->EmitRISC(stream, context, destReg); // this would probably just print the name
    stream << std::endl; // if this does more than that, cry
    declarator_->EmitRISC(stream, context, destReg);
    stream << ":" << std::endl; //function defn */

    parameter_list_->EmitRISC(stream, context, destReg); // this should initliaise the params
}

void DeclaratorWithParameters::Print(std::ostream &stream) const
{
    declarator_->Print(stream);
    stream << "(";
    parameter_list_->Print(stream);
    stream << ")";
}

std::string DeclaratorWithParameters::ReturnID() const
{
    return declarator_->ReturnID();
}

void DeclaratorWithParameters::mapParams(Context &context) const{

    std::vector<std::string> name_list = parameter_list_->returnIDs();
    std::vector<std::string> type_list = parameter_list_->returnTypes();
    std::map<std::string, std::string> param_list;
    for(int i = 0; i<name_list.size(); i++){
        param_list[name_list[i]] = type_list[i];
    }
    context.addParams(declarator_->ReturnID(), param_list);
}
