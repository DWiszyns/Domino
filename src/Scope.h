//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SCOPE_H
#define DOMINO_SCOPE_H

#include <list>
#include "ast/Node/Variable.h"
#include "ScanDef.h"
//#include "ast/Function.h"

class Function;

class Scope {
    std::list<std::unique_ptr<Variable>> variables;
 //   std::list<Function> functions;
    Scope *externalScope;
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
    Scope* getExternalScope();
    void setToDefault();
};


#endif //DOMINO_SCOPE_H
