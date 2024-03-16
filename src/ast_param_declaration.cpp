#include "ast_param_declaration.hpp"

void Parameter::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    // get the type
    std::string typeName = dec_spec_->returnType();
    // get the name
    std::string id = declarator_->ReturnID();
    int mem_offset = context.allocateVariable(id, typeName);
    //dec_spec_->EmitRISC(stream, context, destReg); // this does nothing, it points to the typespec node
    //declarator_->EmitRISC(stream, context, destReg); // this will print variable name into stream, no quiero

}

void Parameter::Print(std::ostream &stream) const {}
