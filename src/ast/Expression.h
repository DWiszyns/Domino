//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_EXPRESSION_H
#define DOMINO_EXPRESSION_H


#include <list>
#include "SimpleExpression.h"
#include "../ScanDef.h"

class Expression {
    std::list <SimpleExpression> simpleExpressions;
    std::list <SymbolType> operators;
    int value;
public:
    Expression(SimpleExpression& simpleExpression);
    void execute();
    void addOperator();
    void addSimpleExpression();

};


#endif //DOMINO_EXPRESSION_H
