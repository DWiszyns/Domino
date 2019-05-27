#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "Scope.h"


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

