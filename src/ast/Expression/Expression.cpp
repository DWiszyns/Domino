//
// Created by dominik on 5/20/19.
//

#include "Expression.h"
#include "Factor/ValueFactor.h"

Node Expression::execute() {
    std::unique_ptr<SimpleExpression> tempSimpleExpression;
    std::list<std::unique_ptr<Factor>> tempFactors;
    std::list<SymbolType> tempMultiplyOperators;
    auto it = additionOperators.begin();
    for(auto &simpleExpression: simpleExpressions){
        if(simpleExpression==*simpleExpressions.begin()){
            tempSimpleExpression=std::make_unique<SimpleExpression>(*simpleExpression);
        }
        else {
            switch(*it){
                case ADD:{
                   tempFactors.push_back(std::make_unique<ValueFactor>
                            (std::make_shared<Node>(tempSimpleExpression->execute()+simpleExpression->execute())));
                    tempSimpleExpression=std::make_unique<SimpleExpression>(std::move(tempFactors),tempMultiplyOperators);
                    break;
                }
                case SUBTRACT: {
                    tempFactors.push_back(std::make_unique<ValueFactor>
                            (std::make_shared<Node>(tempSimpleExpression->execute() - simpleExpression->execute())));
                    tempSimpleExpression = std::make_unique<SimpleExpression>(std::move(tempFactors),tempMultiplyOperators);
                    break;
                }
                default:break;
            }
            ++it;
            tempFactors.clear();
        }
    }

    return tempSimpleExpression->execute();
}


Expression::Expression(std::list<std::unique_ptr<SimpleExpression>> simpleExpressions,
                       std::list<SymbolType> additionOperators) {
    this->simpleExpressions=std::move(simpleExpressions);
    this->additionOperators=std::move(additionOperators);

}

Expression::Expression() = default;

Expression::Expression(const Expression & otherExpression): additionOperators(otherExpression.additionOperators) {
    for(const auto &n:otherExpression.simpleExpressions)
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(*n));

}

Expression &Expression::operator=(const Expression & otherExpression) {
    if (this != &otherExpression) {
        additionOperators = otherExpression.additionOperators;
        for(const auto &n:otherExpression.simpleExpressions)
            simpleExpressions.push_back(std::make_unique<SimpleExpression>(*n));
    }
    return *this;
}
