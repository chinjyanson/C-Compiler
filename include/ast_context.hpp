#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <unordered_map>
#include <string>
#include "ast_node.hpp"

// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).
class Context
{
    /* TODO decide what goes inside here */
private:
    // Variable Table: Name, Type
    std::unordered_map<std::string, std::string> variable_table;

public:

    void AddVariable(const std::string& name, const std::string& type)
    { variable_table[name] = type; }

    bool HasVariable(const std::string& name) const
    { return variable_table.find(name) != variable_table.end(); }

    std::string GetVariableType(const std::string& name) const
    {
        auto it = variable_table.find(name);
        if (it != variable_table.end())
        {
            return it->second;
        }
        else
        {
            // Variable not found
            return "";
        }
    }

};

#endif
