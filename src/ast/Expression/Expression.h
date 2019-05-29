//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_EXPRESSION_H
#define DOMINO_EXPRESSION_H


#include "SimpleExpression.h"

class Expression {
    std::list <std::unique_ptr<SimpleExpression>> simpleExpressions;
    std::list <SymbolType> additionOperators;
public:
    explicit Expression();
    Expression(std::list <std::unique_ptr<SimpleExpression>> simpleExpressions,std::list <SymbolType> additionOperators);
    ~Expression()=default;
    Node execute();
    void addOperator(SymbolType additionOperator);
    Expression(const Expression&);
    Expression& operator=(const Expression& otherExpression);
    //void addSimpleExpression(std::unique_ptr<SimpleExpression> simpleExpression);

};


#endif //DOMINO_EXPRESSION_H
