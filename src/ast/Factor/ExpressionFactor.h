//
// Created by dominik on 5/27/19.
//

#ifndef DOMINO_EXPRESSIONFACTOR_H
#define DOMINO_EXPRESSIONFACTOR_H


#include "Factor.h"
#include "../Expression.h"

class ExpressionFactor: public Factor {
    std::unique_ptr<Expression> expression;
public:
    ExpressionFactor(std::unique_ptr<Expression> expression);
    ~ExpressionFactor();
    Node calculate() override;

};


#endif //DOMINO_EXPRESSIONFACTOR_H
