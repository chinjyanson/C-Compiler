#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ast/declarations/ast_direct_declarator.hpp"
#include "ast_function_definition.hpp"
#include "ast_identifier.hpp"
#include "ast_jump_statement.hpp"
#include "ast_node.hpp"
#include "ast_type_specifier.hpp"
#include "ast_constant.hpp"
#include "ast_context.hpp"
#include "ast/operators/ast_add_op.hpp"
#include "ast/operators/ast_sub_op.hpp"
#include "ast/operators/ast_multiply_op.hpp"
#include "ast/operators/ast_divide_op.hpp"
#include "ast_assign_op.hpp"
#include "ast_declarations.hpp"
#include "ast_variable_init.hpp"
#include "ast_variable_call.hpp"
#include "ast_multiline.hpp"
#include "ast/declarations/ast_declarator_with_parameters.hpp"
#include "ast_param_declaration.hpp"
#include "ast/operators/ast_bitwiseAnd.hpp"
#include "ast/operators/ast_bitwiseOr.hpp"
#include "ast/operators/ast_bitwiseXor.hpp"
#include "ast/operators/ast_logicalOr.hpp"
#include "ast/operators/ast_logicalAnd.hpp"
#include "ast/operators/ast_le_op.hpp"
#include "ast/operators/ast_ge_op.hpp"
#include "ast/operators/ast_lt_op.hpp"
#include "ast/operators/ast_gt_op.hpp"
#include "ast/operators/ast_ls_op.hpp"
#include "ast/operators/ast_rs_op.hpp"
#include "ast/operators/ast_mod_op.hpp"
#include "ast/operators/ast_eq_op.hpp"
#include "ast/operators/ast_ne_op.hpp"
#include "ast/operators/ast_unary_op.hpp"
#include "ast/operators/ast_unary_sign.hpp"
#include "ast/operators/ast_post_op.hpp"
#include "ast_compound_statement.hpp"
#include "ast_nested_statement.hpp"
#include "ast_if_statement.hpp"
#include "ast_while.hpp"
#include "ast_argument.hpp"
#include "ast_function_call.hpp"
#include "ast_for.hpp"
#include "ast_size_of.hpp"
#include "ast_pointer.hpp"
#include "ast_pointer_declarator.hpp"
#include "ast_array.hpp"

extern Node *ParseAST(std::string file_name);

#endif
