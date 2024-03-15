#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

#include "./ast/declarations/ast_direct_declarator.hpp"
#include "ast_function_definition.hpp"
#include "ast_identifier.hpp"
#include "ast_jump_statement.hpp"
#include "ast_node.hpp"
#include "ast_type_specifier.hpp"
#include "ast_constant.hpp"
#include "ast_context.hpp"
#include "./ast/operators/ast_add.hpp"
#include "./ast/operators/ast_sub.hpp"
#include "./ast/operators/ast_multiply.hpp"
#include "./ast/operators/ast_divide.hpp"
#include "./ast/operators/ast_add.hpp"
#include "ast_declarations.hpp"
#include "ast_variable_init.hpp"
#include "ast_variable_call.hpp"

extern Node *ParseAST(std::string file_name);

#endif
