//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_ASSIGNMENT_H
#define DOMINO_ASSIGNMENT_H


#include "../Variable.h"
#include "Statement.h"
#include "../Expression/Expression.h"

class Assignment:public Statement {
    Variable *lvalue;
    std::unique_ptr<Expression> rvalue;
    unsigned int index;
public:
    //mozna sprawdzic czy zmienna nalezy do Scope'a, ale czy tego nie powininem sprawdzic w parserze??
    Assignment();
    Assignment(const Assignment& other);
    Assignment(Variable* lvalue, std::unique_ptr <Expression> expressionRValue, unsigned int i);
    ~Assignment() override;
    Expression getExpression();
    bool isEmptyVariable();
    void execute() override;

};


#endif //DOMINO_ASSIGNMENT_H
