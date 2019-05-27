//
// Created by dominik on 5/27/19.
//

#ifndef DOMINO_EXPRESSIONFACTOR_H
#define DOMINO_EXPRESSIONFACTOR_H


#include "Factor.h"
#include "../Expression.h"

class ExpressionFactor: public Factor {
    Expression expression;
public:
    ExpressionFactor(Expression expression);
    ~ExpressionFactor();
    Node calculate() override;

};


#endif //DOMINO_EXPRESSIONFACTOR_H
