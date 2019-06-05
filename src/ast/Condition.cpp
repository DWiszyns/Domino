//
// Created by dominik on 5/20/19.
//

#include "Condition.h"

bool Condition::evaluate() {
    switch(relativeOperator){
        case EQUALS:
            return expressionLeft->execute()==expressionRight->execute();
        case MORE:
            return expressionLeft->execute()>expressionRight->execute();
        case MOREOREQUAL:
            return expressionLeft->execute()>=expressionRight->execute();
        case LESS:
            return expressionLeft->execute()<expressionRight->execute();
        case LESSOREQUAL:
            return expressionLeft->execute()<=expressionRight->execute();
        case DIFFERENT:
            return expressionLeft->execute()!=expressionRight->execute();
        default: return false;
    }
}

Condition::Condition() {

}

Condition::Condition(Condition &other):relativeOperator(other.relativeOperator) {
    expressionLeft = std::move(other.expressionLeft);
    expressionRight = std::move(other.expressionRight);
}

Condition::Condition(std::unique_ptr<Expression> expressionLeft, std::unique_ptr<Expression> expressionRight,
                     SymbolType relativeOperator):expressionRight(std::move(expressionRight)),
                     expressionLeft(std::move(expressionLeft)),relativeOperator(relativeOperator) {

}
