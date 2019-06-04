//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SCOPE_H
#define DOMINO_SCOPE_H

#include <list>
#include "ast/Variable.h"
#include "ScanDef.h"
//#include "ast/Function.h"

class Function;

class Scope {
    std::list<std::unique_ptr<Variable>> variables;//moze wskazniki na zmienne, zeby mialy dobra wartosc
    std::list<Function> functions;
    Scope *externalScope;
    int allocatedVariables=0;
public:
    Scope();
    Scope(Scope *ext,  std::list<std::unique_ptr<Variable>> variables, std::list <Function> functions) = delete;
    explicit Scope(Scope *ext);
    Scope(const Scope& scope);
    Scope& operator=(const Scope& that)=delete;
    Scope& operator=(Scope &&) noexcept = delete; // Move Assignment
    ~Scope();
    void addVariable(std::unique_ptr<Variable> variable);
    void addFunction(Function function);
    std::list <Function> getFunctions();
    Variable* getVariable(std::string name);


};


#endif //DOMINO_SCOPE_H
