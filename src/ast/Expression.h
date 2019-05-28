//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_EXPRESSION_H
#define DOMINO_EXPRESSION_H


#include <list>
#include "SimpleExpression.h"

class Expression {
    std::list <std::unique_ptr<SimpleExpression>> simpleExpressions;
    std::list <SymbolType> additionOperators;
    int value;
public:
    Expression(std::unique_ptr<SimpleExpression> simpleExpression);
    ~Expression();
    Node execute();
    void addOperator();
    void addSimpleExpression();

};


#endif //DOMINO_EXPRESSION_H
