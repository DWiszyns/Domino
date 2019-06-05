
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
            tempFactor=std::make_unique<ValueFactor>(*factor); //either way we're only interested in value, so even for expressionfactor we calculate it now
        }
        else {
            switch(*it){
                case MULTIPLYSY:
                    tempFactor=std::make_unique<ValueFactor>(std::make_shared<Node>((tempFactor->calculate())*(factor->calculate())));
                    break;
                case DIVIDESY:
                    tempFactor=std::make_unique<ValueFactor>(std::make_shared<Node>((tempFactor->calculate())/(factor->calculate())));
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

SimpleExpression::SimpleExpression(std::list<std::unique_ptr<Factor>> factors,
                                   std::list<SymbolType> multiplicationOperators) {
    this->factors= std::move(factors);
    this->multiplicationOperators= std::move(multiplicationOperators);
}

SimpleExpression::SimpleExpression(const SimpleExpression &otherExpression):
    multiplicationOperators(otherExpression.multiplicationOperators){
    for(const auto &n:otherExpression.factors)
        if(dynamic_cast<ValueFactor*>(n.get()) != nullptr)
            factors.push_back(std::make_unique<ValueFactor>(*n));
        else if(dynamic_cast<ExpressionFactor*>(n.get()) != nullptr)
            factors.push_back(std::make_unique<ExpressionFactor>(*(dynamic_cast<ExpressionFactor*>(n.get()))));
        else
            factors.push_back(std::make_unique<Factor>(*n));
}

SimpleExpression &SimpleExpression::operator=(const SimpleExpression &otherExpression){
    if (this != &otherExpression) {
        multiplicationOperators=otherExpression.multiplicationOperators;
        for(const auto &n:otherExpression.factors)
            if(dynamic_cast<ValueFactor*>(n.get()) != nullptr) factors.push_back(std::make_unique<ValueFactor>(*n));
            else if(dynamic_cast<ExpressionFactor*>(n.get()) != nullptr)
                factors.push_back(std::make_unique<ExpressionFactor>(*(dynamic_cast<ExpressionFactor*>(n.get()))));
            else factors.push_back(std::make_unique<Factor>(*n));
    }
    return *this;
}
