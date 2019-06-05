//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SIMPLEEXPRESSION_H
#define DOMINO_SIMPLEEXPRESSION_H

#include <list>
#include "../../ScanDef.h"
#include "Factor/Factor.h"
#include "Factor/ValueFactor.h"
#include "Factor/ExpressionFactor.h"


class SimpleExpression {
    std::list <std::unique_ptr<Factor>> factors;
    std::list <SymbolType> multiplicationOperators;
public:
    SimpleExpression();
    SimpleExpression(std::list <std::unique_ptr<Factor>> factors,std::list <SymbolType> multiplicationOperators);
    ~SimpleExpression()= default;
    Node execute();
    SimpleExpression(const SimpleExpression& otherExpression);
    SimpleExpression& operator=(const SimpleExpression& otherExpression);

};


#endif //DOMINO_SIMPLEEXPRESSION_H
