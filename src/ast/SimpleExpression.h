//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SIMPLEEXPRESSION_H
#define DOMINO_SIMPLEEXPRESSION_H

#include <list>
#include "Factor/Factor.h"
#include "../ScanDef.h"

class SimpleExpression {
    std::list <Factor> factors;
    std::list <SymbolType> multiplicationOperators;
public:
    SimpleExpression();
    ~SimpleExpression();
    Node execute();
    void addFactor(Factor &factor);
    void addOperator(SymbolType multiplicationOperator);

};


#endif //DOMINO_SIMPLEEXPRESSION_H
