//
// Created by dominik on 5/27/19.
//

#include "ExpressionFactor.h"

ExpressionFactor::~ExpressionFactor() {

}

Node ExpressionFactor::calculate() {
    return expression->execute();
}

ExpressionFactor::ExpressionFactor(std::unique_ptr<Expression> expression):expression(std::move(expression)),Factor(Node (0)) {

}
