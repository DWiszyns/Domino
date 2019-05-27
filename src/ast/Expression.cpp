//
// Created by dominik on 5/20/19.
//

#include "Expression.h"

Expression::Expression(SimpleExpression& simpleExpression) {
    simpleExpressions.push_back(simpleExpression);
}

Node Expression::execute() {
    return Node(0);
}

void Expression::addOperator() {

}

void Expression::addSimpleExpression() {

}
