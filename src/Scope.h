//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SCOPE_H
#define DOMINO_SCOPE_H

#include <list>
#include "ast/Variable.h"
#include "ast/Function.h"
//#include "Parser.h"
#include "ScanDef.h"

class Scope {
    std::list<Variable> variables;
    std::list <Function> functions;
    Scope *externalScope;
public:
    Scope();
    Scope(Scope *ext, std::list<Variable> variables, std::list <Function> functions);
    ~Scope();
    void addVariable(Variable variable);
    void addFunction(Function function);
};


#endif //DOMINO_SCOPE_H
