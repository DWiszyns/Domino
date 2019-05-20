//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_ASSIGNMENT_H
#define DOMINO_ASSIGNMENT_H


#include "Variable.h"
#include "Statement.h"
#include "Expression.h"

class Assignment:public virtual Statement {
    Variable lvalue;
    Expression rvalue;
public:
    Assignment(Variable& lvalue, Expression rvalue);
    ~Assignment();
    void execute();

};


#endif //DOMINO_ASSIGNMENT_H
