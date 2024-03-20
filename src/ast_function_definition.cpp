#include "ast_function_definition.hpp"

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context, int destReg) const
{
    // Store current state of context
    bool was_function = context.is_function;
    int old_mem_offset = context.mem_offset;
    int old_arg_offset = context.arg_offset;
    std::vector<std::map<std::string, std::string>> old_variables;
    for (auto& scope : context.variables) {
        old_variables.push_back(std::move(scope));
    }
    std::vector<std::map<std::string, int>> old_allocs;
    for (auto& scope : context.variable_allocs) {
        old_allocs.push_back(std::move(scope));
    }

    // Flush context
    context.is_function = true;
    context.variables.clear();
    context.variable_allocs.clear();
    // Set up new space
    context.variables.push_back(std::map<std::string, std::string>());
    context.variable_allocs.push_back(std::map<std::string, int>());
    stream << "addi s0, s0, " << old_mem_offset+16 << std::endl;
    context.mem_offset = -16;
    context.arg_offset = 0;

    // Emit assembler directives.
    // TODO: these are just examples ones, make sure you understand
    // the concept of directives and correct them.

    stream << ".text" << std::endl;
    // label?
    declarator_->EmitRISC(stream, context, destReg); // this does the .globl name and name: and start param setup
    if (compound_statement_ != nullptr)
    {
        compound_statement_->EmitRISC(stream, context, destReg);
    }

    // Restore context
    context.is_function = was_function;
    stream << "addi s0, s0, " << -(old_mem_offset+16) << std::endl;
    context.mem_offset = old_mem_offset;
    context.arg_offset = old_arg_offset;
    context.variables.pop_back();
    context.variable_allocs.pop_back();


    for (auto& scope : old_variables) {
        context.variables.push_back(std::move(scope));
    }
    old_variables.clear();
    for (auto& scope : old_allocs) {
        context.variable_allocs.push_back(std::move(scope));
    }
    old_allocs.clear();

}

void FunctionDefinition::Print(std::ostream &stream) const
{
    declaration_specifiers_->Print(stream);
    stream << " ";

    declarator_->Print(stream);
    stream << "() {" << std::endl;

    if (compound_statement_ != nullptr)
    {
        compound_statement_->Print(stream);
    }
    stream << "}" << std::endl;
}
