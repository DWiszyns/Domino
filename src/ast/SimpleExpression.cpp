#include <utility>

#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "SimpleExpression.h"
#include "Factor/ValueFactor.h"

Node SimpleExpression::execute() {
    std::unique_ptr<Factor> tempFactor;
    auto it = multiplicationOperators.begin();
    for(auto &factor: factors){
        if(factor==*factors.begin()){
            tempFactor=std::make_unique<Factor>(factor->calculate());
        }
        else {
            switch(*it){
                case MULTIPLYSY:
                    tempFactor=std::make_unique<Factor>(tempFactor->calculate()*factor->calculate());
                    break;
                case DIVIDESY:
                    tempFactor=std::make_unique<Factor>(tempFactor->calculate()/factor->calculate());
                    break;
                default:break;
            }
            ++it;
        }
    }

    return tempFactor->calculate();
}

SimpleExpression::SimpleExpression() {

}

//void SimpleExpression::addOperator(SymbolType newOperator) {
//    multiplicationOperators.push_back(newOperator);
//}

//void SimpleExpression::addFactor(std::unique_ptr<Factor> factor) {
//    factors.push_back(std::move(factor));
//}

//SimpleExpression::SimpleExpression(std::unique_ptr<Factor> factor) {
//    factors.push_back(std::move(factor));
//}

SimpleExpression::SimpleExpression(std::list<std::unique_ptr<Factor>> factors,
                                   std::list<SymbolType> multiplicationOperators) {
    this->factors= std::move(factors);
    this->multiplicationOperators= std::move(multiplicationOperators);
}

SimpleExpression::SimpleExpression(const SimpleExpression &otherExpression):
    multiplicationOperators(otherExpression.multiplicationOperators){
    for(const auto &n:otherExpression.factors)
        factors.push_back(std::make_unique<Factor>(*n));

}

SimpleExpression &SimpleExpression::operator=(const SimpleExpression &otherExpression){
    if (this != &otherExpression) {
        multiplicationOperators=otherExpression.multiplicationOperators;
        for(const auto &n:otherExpression.factors)
            factors.push_back(std::make_unique<Factor>(*n));
    }
    return *this;
}
