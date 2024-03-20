#include "ast_param_declaration.hpp"

void Parameter::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    std::string typeName = dec_spec_->returnType();
    std::string id = declarator_->ReturnID();
    int param_size = dec_spec_->getSize();
    int param_reg = context.findParamReg();

    if(context.is_call){
        context.arg_offset += param_size;
        stream << "lw x" << param_reg << ", " << context.arg_offset << "(s0)" << std::endl;
    }

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

    //context.freeRegister(param_reg);
}

void Parameter::Print(std::ostream &stream) const {}
