//
// Created by dominik on 5/20/19.
//
#include <utility>
#include "Scope.h"
#include "ast/Function.h"


Scope::~Scope() {
}


Scope::Scope() {
    externalScope=nullptr;
}


//void Scope::addFunction(Function function) {
//    functions.push_back(function);
//
//}
//
//std::list<Function> Scope::getFunctions() {
//    return functions;
//}

Scope::Scope(Scope *ext):externalScope(ext){

}

Variable *Scope::getVariable(std::string name) {
    for(auto& x:variables)
        if(x->getName()==name) return x.get();
    if(externalScope!=nullptr){
        for(auto& x:externalScope->variables)
            if(x->getName()==name) return x.get();
    }
    return nullptr;
}

void Scope::addVariable(std::unique_ptr<Variable> variable) {
    variables.push_back(std::move(variable));

}

Scope::Scope(const Scope &scope):externalScope(scope.externalScope)//,functions(scope.functions),
{
    for(auto &i : scope.variables)
        variables.push_back(std::make_unique<Variable>(*i));
}

Scope *Scope::getExternalScope() {
    return externalScope;
}

void Scope::setToDefault() {
    for(auto &i: variables)
        i->setNodeToDefault();
}


