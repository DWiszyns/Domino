//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_ASSIGNMENT_H
#define DOMINO_ASSIGNMENT_H


#include "../Node/Variable.h"
#include "Statement.h"
#include "../Expression/Expression.h"

class Assignment:public Statement {
    Variable *lvalue;
    std::unique_ptr<Expression> rvalue;
    unsigned int index;
public:
    Assignment();
    Assignment(const Assignment& other);
    Assignment(Variable* lvalue, std::unique_ptr <Expression> expressionRValue, unsigned int i);
    ~Assignment() override;
    Expression getExpression();
    bool isEmptyVariable();
    void execute() override;

};


#endif //DOMINO_ASSIGNMENT_H
