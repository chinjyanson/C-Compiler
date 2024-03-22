#include <fstream>
#include <iostream>

#include "cli.h"
#include "ast.hpp"

Node *Parse(CommandLineArguments &args)
{
    std::cout << "Parsing: " << args.compile_source_path << std::endl;
    auto root = ParseAST(args.compile_source_path);
    std::cout << "AST parsing complete" << std::endl;
    return root;
}

void PrettyPrint(Node *root, CommandLineArguments &args)
{
    auto output_path = args.compile_output_path + ".printed";

    std::cout << "Printing parsed AST..." << std::endl;
    std::ofstream output(output_path, std::ios::trunc);
    root->Print(output);
    output.close();
    std::cout << "Printed parsed AST to: " << output_path << std::endl;
}

void Compile(Node *root, CommandLineArguments &args)
{
    Context ctx;

    std::cout << "Compiling parsed AST..." << std::endl;
    std::ofstream output(args.compile_output_path, std::ios::trunc);
    root->EmitRISC(output, ctx, 10);
    output.close();
    std::cout << "Compiled to: " << args.compile_output_path << std::endl;
}

int main(int argc, char **argv)
{
    auto command_line_arguments = ParseCommandLineArgs(argc, argv);

    auto ast_root = Parse(command_line_arguments);

    ast_root->Print(std::cout);

    if (ast_root == nullptr)
    {
        std::cerr << "The root of the AST was a null pointer. Likely the root was never initialised correctly during parsing." << std::endl;
        return 3;
    }

    PrettyPrint(ast_root, command_line_arguments);
    Compile(ast_root, command_line_arguments);

    delete ast_root;
    return 0;
}
