//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_STATEMENT_H
#define DOMINO_STATEMENT_H


#include "../../Scope.h"

class Statement {
    Scope scope;
    int a=1;
public:
    Statement();
    Statement(Scope scope);
    virtual ~Statement();
    virtual void execute();

};


#endif //DOMINO_STATEMENT_H
