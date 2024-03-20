#include "ast_declarations.hpp"

void Declarations::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    // get the type
    std::string typeName = dec_spec_->returnType();
    // get a list of all the declarator names
    std::vector<std::string> id_list = init_declarator_list_->returnIDs();
    // iterate through that list and add all the names+type to variables in context
    for(int i = 0; i < id_list.size(); i++){
        context.declareVariable(id_list[i], typeName);
    }

    dec_spec_->EmitRISC(stream, context, destReg); // this does nothing, it points to the typespec node
    init_declarator_list_->EmitRISC(stream, context, destReg); // this will call variable init

}

void Declarations::Print(std::ostream &stream) const {
    dec_spec_->Print(stream);
    stream << " ";
    init_declarator_list_->Print(stream);
}
