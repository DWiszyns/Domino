//
// Created by dominik on 5/20/19.
//

#include "SimpleExpression.h"

Node SimpleExpression::execute() {
    return Node(0);
}

SimpleExpression::SimpleExpression() {

}

SimpleExpression::~SimpleExpression() {

}

void SimpleExpression::addOperator(SymbolType newOperator) {
    multiplicationOperators.push_back(newOperator);

}

void SimpleExpression::addFactor(Factor &factor) {
    factors.push_back(factor);

}
