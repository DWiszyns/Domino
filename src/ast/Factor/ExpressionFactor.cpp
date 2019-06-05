//
// Created by dominik on 5/27/19.
//

#include "ExpressionFactor.h"
#include "../Expression/Expression.h"


ExpressionFactor::~ExpressionFactor() {

}

Node ExpressionFactor::calculate() {
    return expression->execute();
}

ExpressionFactor::ExpressionFactor(std::unique_ptr<Expression> expression):expression(std::move(expression)),Factor(std::make_unique<Node>(Node (0))) {

}

ExpressionFactor::ExpressionFactor(const ExpressionFactor &otherExpression):Factor(std::make_unique<Node>(Node (0))) {
    expression=std::make_unique<Expression>(std::move(*otherExpression.expression));
}

ExpressionFactor::ExpressionFactor(const Factor &otherFactor) : Factor(otherFactor) {

}

