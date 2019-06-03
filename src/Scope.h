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
    std::list<Variable> variables;//moze wskazniki na zmienne, zeby mialy dobra wartosc
    std::list<Function> functions;
    Scope *externalScope;
public:
    Scope();
    Scope(Scope *ext,  std::list<Variable> variables, std::list <Function> functions);
    Scope(Scope *ext);
    ~Scope();
    void addVariable(Variable variable);
    void addFunction(Function function);
    std::list <Function> getFunctions();
    std::list<Variable> getVariables();
    Variable getVariable(std::string name);
    Rational& operator=(const Rational& other); // copy assignment
    Rational& operator=(Rational&& other) noexcept; // move assignment


};


#endif //DOMINO_SCOPE_H
