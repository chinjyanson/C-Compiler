#include "ast_function_call.hpp"

void FunctionCall::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    std::string f_name = name_->ReturnID();
    bool was_call = context.is_call;
    context.is_call = true;
    if(args_!=nullptr){
        args_->EmitBackwards(stream, context, destReg);
    }
    stream << "call " << f_name << std::endl;
    context.is_call = was_call;
}

void FunctionCall::Print(std::ostream &stream) const {}

 int FunctionCall::getSize() const{
    /* get f_type from context probably
    if(f_type=="char"){
        return 1;
    }
    else if(f_type=="float"){
        return 8;
    }
    else if(f_type=="double"){
        return 4;
    }
    else{
        return 4;
    }
    */
}
