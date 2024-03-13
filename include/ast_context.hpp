#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <map>
#include <string>

// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).
class Context
{
public:
    /* TODO decide what goes inside here */

    // Free memory stack offset
    int mem_offset = -16;
    // Variable stored table:
    std::map<std::string, int> variable_allocs; // Variable name - stack offset

    //Global variable table:
    std::map<std::string, std::string> variables; // Variable name - Type

    //Function table:
    std::map<std::string, std::string> functions; // Name - Type
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
    int allocateVariable(std::string variable_name, std::string variable_type){
        if (variable_type == "int"){
            mem_offset -= 4;
        }
        if (variable_type == "double"){
            mem_offset -= 8;
        }
        if (variable_type == "long"){
            mem_offset -= 8;
        }
        variable_allocs[variable_name] = mem_offset;
        variables[variable_name] = variable_type;
        return mem_offset;
    }
    void addFunction(std::string func_name, std::string func_type){
        functions[func_name] = func_type;
        //might add the params here idk yet
    }

    //Getters
    int findVariable(std::string variable_name) const {
        auto it = variable_allocs.find(variable_name);
        if (it == variable_allocs.end()) {
            return -1;
        }
        return it->second;
    }
    std::string getVariableType(std::string variable_name) const {
        auto it = variables.find(variable_name);
        if (it == variables.end()) {
            return "Variable not found";
        }
        return it->second;
    }


};

#endif
