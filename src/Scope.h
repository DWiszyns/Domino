//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SCOPE_H
#define DOMINO_SCOPE_H

#include <iostream>
#include <list>
#include <ast/Variable.h>
#include <ast/Function.h>
//#include "Parser.h"
#include "ScanDef.h"

class Scope {
    struct Array{
    };

    std::list<Variable> variables;
    std::list <Array> arrays;
    std::list <Function> functions;
    Scope *externalScope;
public:
    Scope();
    Scope(Scope *ext, std::list<Variable> variables, std::list <Array> arrays,std::list <Function> functions);
    ~Scope();
    void addVariable(Variable variable);
    void addArray(Array array);
    void addFunction(Function function);
    //lista array, zmiennych i funkcji
};


#endif //DOMINO_SCOPE_H
