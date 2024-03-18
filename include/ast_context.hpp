#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <map>
#include <string>
#include <vector>

// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).
class Context
{
public:
    /* TODO decide what goes inside here */
    bool is_function;

    // Free memory stack offset
    int mem_offset = -16;
    // Variable stored table:
    std::vector<std::map<std::string, int>> variable_allocs; // Scope: Variable name - stack offset

    //Global variable table:
    std::vector<std::map<std::string, std::string>> variables; // Scope: Variable name - Type

    //Function table:
    std::map<std::string, std::string> functions; // Name   - Type
    std::map<std::string, std::map<std::string, std::string>> function_params; // Name - Param list (Name - Type)
    std::map<std::string, std::map<std::string, std::string>> function_vars; // Name - Local variable list (Name - Type)

    // Available registers
    int registers[32] =
    { 1, //x0 zero address: index = 0
    1, //x1 ra return address: index = 1
    1,  //x2 sp stack pointer: index = 2
    1,  //x3 gp global pointer: index = 3
    1, // Thread pointer: index = 4
    0, 0, 0,  //t0-t2 Temporary registers: index = 5-7
    1, 1,  //s0-s1 Callee-saved registers: index = 8-9
    0, 0, 0, 0, 0, 0, 0, 0, //a0-a7 Argument registers: index = 10-17
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, //s2-s11 Callee-saved registers: index = 18-27
    0, 0, 0, 0, //t3-t6 Temporary registers: index = 28-31
    };


    // Generic register stuff
    void useRegister(int i){
        registers[i] = 1;
    }

    void freeRegister(int i){
        registers[i] = 0;
    }

    int getFreeRegister(){
        for (int i = 5; i < 31; i++){
            if (registers[i] == 0 ){
                useRegister(i);
                return i;
            }
        }
    return -1;
    }

    int findParamReg(){
        for (int i = 10; i < 17; i++){
            if (registers[i] == 0 ){
                useRegister(i);
                return i;
            }
        }
    return -1;
    }

    //Setters
    void declareVariable(std::string variable_name, std::string variable_type){
        variables[variables.size()-1][variable_name] = variable_type;
    }
    
    int allocateVariable(std::string variable_name, std::string variable_type){
        if (variable_type == "int"){
            mem_offset -= 4;
        }
        if (variable_type == "double"){
            mem_offset -= 8;
        }
        if (variable_type == "float"){
            mem_offset -= 4;
        }
        if (variable_type == "long"){
            mem_offset -= 8;
        }
        variable_allocs[variable_allocs.size()-1][variable_name] = mem_offset;
        declareVariable(variable_name, variable_type);
        return mem_offset;
    }
    void addFunction(std::string func_name, std::string func_type){
        functions[func_name] = func_type;
        // might add the params here idk yet
    }

    //Getters
    bool checkVariable(std::string variable_name) const {
        auto it = variables[variables.size()-1].find(variable_name);
        if (it == variables[variables.size()-1].end()) {
            return false;
        }
        return true;
    }
    int checkCurrentScopeForVarAlloc(std::string variable_name) const {
        auto it = variable_allocs[variable_allocs.size()-1].find(variable_name);
        if (it == variable_allocs[variable_allocs.size()-1].end()) {
            return -1;
        }
        return it->second;
    }
    int findVariable(std::string variable_name) const {
        for(int i = variable_allocs.size()-1; i >= 0; i--){
            auto it = variable_allocs[i].find(variable_name);
            if (it == variable_allocs[i].end()) {
                if(i==0){
                    return -1;
                }
                continue;
            }
            return it->second;
        }
    }

    std::string getVariableType(std::string variable_name) const {
        for(int i = variables.size()-1; i >= 0; i--){
            auto it = variables[i].find(variable_name);
            if (it == variables[i].end()) {
                if(i==0){
                    return "Variable not found";
                }
                continue;
            }
            return it->second;
        }
    }
};

#endif


// when entering a new scope:
// create a new scope in the list
// check if youre calling a compound list due to a function or not

// store the size of the current variable list probably in the node cpp
// store the value of the current mem_offset
// store current state of is_function

// if yes: (function)
// push the current stack onto a seperate list so it's empty
// increment the stack pointer by mem_offset so it can start afresh

// if no: (just {} for ifs and stuff)
// dont move the current vars away

// at the end of the scope:
// pop all the variables after the index[size] in the variable list
// revert mem_offset
// revert is_function
