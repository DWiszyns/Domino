//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_CONDITIONALEXPRESSION_H
#define DOMINO_CONDITIONALEXPRESSION_H

#include "Condition.h"
#include <list>

class ConditionalExpression {
    std::list<std::unique_ptr<Condition>> conditions;
    std::list<SymbolType> logicalOperators;
public:
    ConditionalExpression();
    ConditionalExpression(std::list<std::unique_ptr<Condition>> conditions, std::list<SymbolType > logicalOperator);
    ConditionalExpression(ConditionalExpression &other);
    ~ConditionalExpression()=default;
    bool evaluate();

};


#endif //DOMINO_CONDITIONALEXPRESSION_H
