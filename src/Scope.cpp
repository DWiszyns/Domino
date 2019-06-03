#include <utility>

#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "Scope.h"
#include "ast/Function.h"


Scope::~Scope() {

}

Scope::Scope(Scope *ext, std::list<Variable> variables,std::list<Function> functions):externalScope(ext),
        variables(std::move(variables)),functions(std::move(functions)){

}

Scope::Scope() {
    externalScope=nullptr;

}

void Scope::addVariable(Variable variable) {
    variables.push_back(variable);

}


void Scope::addFunction(Function function) {
    functions.push_back(function);

}

std::list<Function> Scope::getFunctions() {
    return functions;
}

std::list<Variable> Scope::getVariables() {
    return variables;
}

Scope::Scope(Scope *ext):externalScope(ext),functions(ext->functions),variables(ext->variables) {//maybe they need to be pointers to variables

}

Variable Scope::getVariable(std::string name) {
    for(auto& x:variables)
        if(x.getName()==name) return x;
     return Variable();
}

