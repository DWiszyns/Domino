//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SIMPLEEXPRESSION_H
#define DOMINO_SIMPLEEXPRESSION_H

#include <list>
#include "../ScanDef.h"
#include "Factor/Factor.h"


class SimpleExpression {
    std::list <std::unique_ptr<Factor>> factors;
    std::list <SymbolType> multiplicationOperators;
public:
    SimpleExpression();
    ~SimpleExpression();
    Node execute();
    void addFactor(std::unique_ptr<Factor> factor);
    void addOperator(SymbolType multiplicationOperator);

};


#endif //DOMINO_SIMPLEEXPRESSION_H
