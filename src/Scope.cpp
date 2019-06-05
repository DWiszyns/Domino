#include <utility>

#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "Scope.h"
#include "ast/Function.h"


Scope::~Scope() {
}
/*
Scope::Scope(Scope *ext, std::list<std::unique_ptr<Variable>> variables,std::list<Function> functions):externalScope(ext),
        variables(std::move(variables)),functions(std::move(functions)){

}
 */

Scope::Scope() {
    externalScope=nullptr;
}


void Scope::addFunction(Function function) {
    functions.push_back(function);

}

std::list<Function> Scope::getFunctions() {
    return functions;
}

Scope::Scope(Scope *ext):externalScope(ext){//maybe they need to be pointers to variables

}

Variable *Scope::getVariable(std::string name) {
    for(auto& x:variables)
        if(x->getName()==name) return x.get();
    if(externalScope!=nullptr){
        for(auto& x:externalScope->variables)
            if(x->getName()==name) return x.get();
    }
    Variable x;
    return &x;
}

void Scope::addVariable(std::unique_ptr<Variable> variable) {
    variables.push_back(std::move(variable));

}

Scope::Scope(const Scope &scope):functions(scope.functions),externalScope(scope.externalScope){
    for(auto &i : scope.variables)
        variables.push_back(std::make_unique<Variable>(*i));
}

Scope *Scope::getExternalScope() {
    return externalScope;
}

void Scope::setExternalScope(Scope *scope) {
    externalScope=scope;

}

void Scope::setToDefault() {
    for(auto &i: variables)
        i->setNodeToDefault();
}


