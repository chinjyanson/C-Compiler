#include "ast_variable_init.hpp"

void VariableInit::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    //but then how do you seperate function names and variable names??
    // will i need this for pointers? maybe, i'll see when i get to pointers ig


    // check if not null pointer
    if(initializer_!=nullptr){
        //load the init value into said register
        initializer_->EmitRISC(stream, context, destReg); //this'll put the value into destReg var_reg (li reg [value])
    }

    std::string variable_name = declarator_->ReturnID();
    std::string variable_type = context.getVariableType(variable_name);
    int check_var = context.checkCurrentScopeForVarAlloc(variable_name);
    if(check_var == -1){

        int mem_offset = context.allocateVariable(variable_name, variable_type);
        stream << "sw x" << destReg << ", " << mem_offset << "(s0)" << std::endl;

    }
    // else
    // complain
    // throw an error
    // idk how to actually do that in code tho ngl

}

void VariableInit::Print(std::ostream &stream) const {
    declarator_->Print(stream);
    if(initializer_!=nullptr){
        stream << " = ";
        initializer_->Print(stream);
    }
}

std::string VariableInit::ReturnID() const {
    return declarator_->ReturnID();
}
