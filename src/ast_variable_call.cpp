#include "ast_variable_call.hpp"

void VariableCall::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    std::string variable_name = identifier_;

    bool check_var = context.checkVariable(variable_name);
    if(check_var == true){
        int mem_offset = context.findVariable(variable_name);
        if(mem_offset != -1){
            stream << "lw x" << destReg << ", " << mem_offset << "(s0)" << std::endl;
        }
        // how did you get here

        // check if its already been alllocated memory
        // if yes, then load the memory into dest reg
        // if no, screaming, crying, throwing up (an error)
    }
    // else
    // complain
    // throw an error
    // idk how to actually do that in code tho ngl
}

void VariableCall::UpdateVar(std::ostream &stream, Context &context, int destReg) const {
    std::string variable_name = identifier_;
    bool check_var = context.checkVariable(variable_name);
    if(check_var == true){
        int mem_offset = context.findVariable(variable_name);
        if(mem_offset != -1){
            stream << "sw x" << destReg << ", " << mem_offset << "(s0)" << std::endl;
        }
    }
}

void VariableCall::Print(std::ostream &stream) const {}
