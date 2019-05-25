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
