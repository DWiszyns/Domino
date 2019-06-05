//
// Created by dominik on 5/20/19.
//

#include "Condition.h"

bool Condition::evaluate() {
    switch(relativeOperator){
        case EQUALS:
            return negative ^ expressionLeft->execute()==expressionRight->execute();
        case MORE:
            return negative ^ expressionLeft->execute()>expressionRight->execute();
        case MOREOREQUAL:
            return negative ^ expressionLeft->execute()>=expressionRight->execute();
        case LESS:
            return negative ^ expressionLeft->execute()<expressionRight->execute();
        case LESSOREQUAL:
            return negative ^ expressionLeft->execute()<=expressionRight->execute();
        case DIFFERENT:
            return negative ^ expressionLeft->execute()!=expressionRight->execute();
        default: return false;
    }
}

Condition::Condition() {

}

Condition::Condition(Condition &other):relativeOperator(other.relativeOperator),negative(other.negative) {
    expressionLeft = std::move(other.expressionLeft);
    expressionRight = std::move(other.expressionRight);
}

Condition::Condition(std::unique_ptr<Expression> expressionLeft, std::unique_ptr<Expression> expressionRight,
                     SymbolType relativeOperator,bool negative):expressionRight(std::move(expressionRight)),
                     expressionLeft(std::move(expressionLeft)),relativeOperator(relativeOperator),negative(negative) {

}

Condition::Condition(std::unique_ptr<Expression> expressionLeft, bool expressionRight, SymbolType relativeOperator,
                     bool negative):expressionLeft(std::move(expressionLeft)),relativeOperator(relativeOperator),
                     negative(negative) {
    Node node(false);
    std::list<std::unique_ptr<Factor>> factorsList;
    factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(expressionRight)));
    std::list<SymbolType> symbols;
    std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
    std::list<SymbolType> addSymbols;
    simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(factorsList),symbols));
    this->expressionRight=std::make_unique<Expression>(std::move(simpleExpressions),addSymbols);

}
