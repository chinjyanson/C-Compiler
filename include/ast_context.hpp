#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <map>
#include <string>
#include <vector>
#include <cmath>

// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).
class Context
{
public:
    /* TODO decide what goes inside here */
    int is_function = 0;
    bool function_scope = false;
    int n_branches = 0;
    int n_labels = 0;
    std::vector<std::string> labels; // for function returns before we exit them

    // Free memory stack offset
    int mem_offset = -16;
    // Variable stored table:
    std::vector<std::map<std::string, int>> variable_allocs; // Scope: Variable name - stack offset

    //Global variable table:
    std::vector<std::map<std::string, std::string>> variables; // Scope: Variable name - Type
    std::vector<std::vector<std::string>> pointers; //  Scope: Pointers
    std::vector<std::map<std::string, int>> arrays; // Scope: Array name - size

    //Function table:
    std::map<std::string, std::string> functions; // Function name - Type
    std::map<std::string, int> function_size; // Name - Memory needed
    std::map<std::string, std::map<std::string, std::string>> function_params; // Name - Param list (Name - Type)
    std::map<std::string, std::map<std::string, std::string>> function_vars; // Name - Local var list (Name - Type)
    std::map<std::string, std::string> temp_vars;

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

    void freeParamRegs(){
        for (int i = 10; i < 17; i++){
            if (registers[i] == 1 ){
                registers[i] = 0;
            }
        }
    }

    //
    std::string createBranch(){
        n_branches++;
        return "L"+std::to_string(n_branches);
    }
    std::string createLabel() {
        n_labels += 1;
        std::string label_name = "end"+std::to_string(n_labels);
        labels.push_back(label_name);
        return label_name;
    }

    std::string getLabel(){
       return labels.back();
    }


    int checkSize(std::string type_){
        if (type_ == "char"){
            return 1;
        }
        else if (type_ == "double"){
            return 8;
        }
        else if (type_ == "long"){
            return 8;
        }
        else{
            return 4;
        }
    }
    int checkFunctionSize(const std::string& func_name) {
        int stacksize = 0;
        auto it_params = function_params.find(func_name);
        if (it_params != function_params.end()) {
            const auto& params = it_params->second;
            for (const auto& param : params) {
                stacksize += checkSize(param.second);
            }
        }
        // Check function variables
        auto it_vars = function_vars.find(func_name);
        if (it_vars != function_vars.end()) {
            const auto& vars = it_vars->second;
            for (const auto& var : vars) {
                stacksize += checkSize(var.second);
            }
        }
        return stacksize;
    }
    int roundStackSize(int num){
        int multiplier = ceil((double)num/16);
        return (multiplier*16) + 16;
    }
    void isFunctionCall(){
        is_function = 1;
    }

    //Setters
    void declareVariable(std::string variable_name, std::string variable_type){
        if(variables.size()==0){
            variables.push_back(std::map<std::string, std::string>());
        }
        variables[variables.size()-1][variable_name] = variable_type;
    }
    void addPointer(std::string variable_name){
        if(pointers.size()==0){
            pointers.push_back(std::vector<std::string>());
        }
        pointers[pointers.size()-1].push_back(variable_name);
    }
    void AddArray(std::string variable_name, int size){
        if(arrays.size()==0){
            arrays.push_back(std::map<std::string, int>());
        }
        arrays[arrays.size()-1][variable_name] = size;
    }

    int allocateVariable(std::string variable_name, std::string variable_type){
        if(variable_allocs.size()==0){
            variable_allocs.push_back(std::map<std::string, int>());
        }
        int array_size = checkArraySize(variable_name);
        if(array_size==-1){
            array_size = 1;
        }
        mem_offset -= (checkSize(variable_type)*array_size);
        variable_allocs[variable_allocs.size()-1][variable_name] = mem_offset;
        declareVariable(variable_name, variable_type);
        return mem_offset;
    }
    void addFunction(std::string func_name, std::string func_type){
        functions[func_name] = func_type;
        // might add the params here idk yet
    }
    std::string getFunctionType(std::string func_name){
        auto it = functions.find(func_name);
        if (it == functions.end()) {
            return "Not found";
        }
        return it->second;
    }
    void addParams(std::string func_name, std::map<std::string, std::string> param_list){
        function_params[func_name] = param_list;
    }
    void addFunctionVars(std::string func_name){
        function_vars[func_name] = temp_vars;
    }
    void setFunctionSize(std::string func_name, int f_size){
        function_size[func_name] = f_size;
    }

    //Getters
    bool checkVariable(std::string variable_name) const {
        auto it = variables[variables.size()-1].find(variable_name);
        if (it == variables[variables.size()-1].end()) {
            return false;
        }
        return true;
    }
    bool checkPointer(std::string variable_name) const {
        for(int i = 0; i < pointers[pointers.size()-1].size(); i++){
            if (pointers[pointers.size()-1][i] == variable_name) {
                return true;
            }
        }
        return false;
    }
    int checkArraySize(std::string variable_name) const{
        if(arrays.size()!=0){
            auto it = arrays[arrays.size()-1].find(variable_name);
            if (it == arrays[arrays.size()-1].end()) {
                return -1;
            }
            return it->second;
        }
        return -1;
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

    std::map<std::string, std::string> returnParamList(std::string func_name) const {
        auto it = function_params.find(func_name);
        return it->second;
    }

    int getFunctionSize(std::string func_name){
        auto it = function_size.find(func_name);
        return it->second;
    }
    void addTempVar(std::string var_name, std::string var_type){
        temp_vars[var_name] = var_type;
    }
    void clearTempVars(){
        temp_vars.clear();
    }

};

#endif
