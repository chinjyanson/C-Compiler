#include "ast_variable_call.hpp"

void VariableCall::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    std::string variable_name = identifier_;

    int mem_offset = context.findVariable(variable_name);
    if(mem_offset != -1){
        stream << "lw x" << destReg << ", " << mem_offset << "(s0)" << std::endl;
    }
        // how did you get here

        // check if its already been alllocated memory
        // if yes, then load the memory into dest reg
        // if no, screaming, crying, throwing up (an error)
    // else
    // complain
    // throw an error
    // idk how to actually do that in code tho ngl
}

void VariableCall::UpdateVar(std::ostream &stream, Context &context, int destReg) const {
    std::string variable_name = identifier_;
    int mem_offset = context.findVariable(variable_name);
    if(mem_offset != -1){
        stream << "sw x" << destReg << ", " << mem_offset << "(s0)" << std::endl;
    }
}

void VariableCall::Print(std::ostream &stream) const {
    stream << identifier_;
}

std::string VariableCall::ReturnID() const {
    return identifier_;
}

int VariableCall::getSize(Context &context) const{
    std::string type_ = context.getVariableType(identifier_);
    if(type_=="char"){
        return 1;
    }
    else if(type_=="double"){
        return 8;
    }
    else if(type_=="long"){
        return 8;
    }
    else{
        return 4;
    }
}
