#include "ast_param_declaration.hpp"

void Parameter::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    std::string typeName = dec_spec_->returnType();
    std::string id = declarator_->ReturnID();

    int mem_offset = context.allocateVariable(id, typeName);
    int param_reg = context.findParamReg();

    //dec_spec_->EmitRISC(stream, context, destReg); // this does nothing, it points to the typespec node
    //declarator_->EmitRISC(stream, context, destReg); // this will print variable name into stream, no quiero

    if(typeName == "float"){
        // it doesn't use the normal sw bc its big
    }
    else if(typeName == "double"){
        // same
    }
    else{
        stream << "sw x" << param_reg << ", " << mem_offset << "(s0)" << std::endl;
    }


}

void Parameter::Print(std::ostream &stream) const {}
