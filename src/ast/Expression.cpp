//
// Created by dominik on 5/20/19.
//

#include "Expression.h"

Node Expression::execute() {
    return Node(0);
}

void Expression::addOperator() {

}

void Expression::addSimpleExpression() {

}

Expression::~Expression() {

}

Expression::Expression(std::unique_ptr<SimpleExpression> simpleExpression) {
    simpleExpressions.push_back(std::move(simpleExpression));

}
