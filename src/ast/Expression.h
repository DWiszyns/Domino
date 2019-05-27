//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_EXPRESSION_H
#define DOMINO_EXPRESSION_H


#include <list>
#include "SimpleExpression.h"

class Expression {
    std::list <SimpleExpression> simpleExpressions;
    std::list <SymbolType> additionOperators;
    int value;
public:
    Expression(SimpleExpression& simpleExpression);
    Node execute();
    void addOperator();
    void addSimpleExpression();

};


#endif //DOMINO_EXPRESSION_H
