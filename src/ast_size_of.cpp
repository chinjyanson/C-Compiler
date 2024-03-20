#include "ast_size_of.hpp"
#include "ast_context.hpp"

void SizeOf::Print(std::ostream &stream) const
{
    stream << "sizeof(";
    type_->Print(stream);
    stream << ")";
}

void SizeOf::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    int size = type_->getSize();

    if (size == -1){
        std::string var_name = type_->ReturnID();
        std::string type = context.getVariableType(var_name);
        if(type == "int"){
            size = 4;
        }
        else if(type == "char"){
            size = 1;
        }
    }

    stream << "li " << destReg << ", " << size << std::endl;
}

int SizeOf::getSize() const
{
    return type_->getSize();
}

