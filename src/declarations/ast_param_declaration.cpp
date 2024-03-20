#include "ast_param_declaration.hpp"

void Parameter::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    std::string typeName = dec_spec_->returnType();
    std::string id = declarator_->ReturnID();
    int param_reg = context.findParamReg();

    int mem_offset = context.allocateVariable(id, typeName);

    //dec_spec_->EmitRISC(stream, context, destReg); // this does nothing, it points to the typespec node
    //declarator_->EmitRISC(stream, context, destReg); // this will print variable name into stream, no quiero

    if(typeName == "float"){
       stream << "fsw f" << param_reg << ", " << mem_offset << "(s0)" << std::endl;
    }
    else if(typeName == "double"){
        // same
        stream << "fsw f" << param_reg << ", " << mem_offset << "(s0)" << std::endl;
    }
    else if(typeName == "long"){
        stream << "sw x" << param_reg << ", " << mem_offset << "(s0)" << std::endl;
    }
    else{
        stream << "sw x" << param_reg << ", " << mem_offset << "(s0)" << std::endl;
    }

}

void Parameter::Print(std::ostream &stream) const {
    dec_spec_->Print(stream);
    stream << " ";
    declarator_->Print(stream);
}

std::string Parameter::ReturnID() const{
    return declarator_->ReturnID();
}

std::string Parameter::returnType() const{
    return dec_spec_->returnType();
}
