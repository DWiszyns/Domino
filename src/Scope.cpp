//
// Created by dominik on 5/20/19.
//

#include "Scope.h"


Scope::~Scope() {

}

/*Scope::Scope(Scope *ext, std::list<Scope::Variable> variables, std::list<Scope::Array> arrays,
             std::list<Scope::Function> functions):externalScope(ext),variables(variables),
             arrays(arrays),functions(functions){

}*/

Scope::Scope() {
    externalScope=nullptr;

}

void Scope::addVariable(Variable variable) {
    variables.push_back(variable);

}

void Scope::addArray(Scope::Array array) {
    arrays.push_back(array);

}

void Scope::addFunction(Function function) {
    functions.push_back(function);

}

