#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "ConditionalExpression.h"

ConditionalExpression::ConditionalExpression() {

}

ConditionalExpression::ConditionalExpression(std::list<std::unique_ptr<Condition>> conditions,
                                             std::list<SymbolType> logicalOperator):conditions(std::move(conditions)),
                                             logicalOperators(std::move(logicalOperator)){

}

ConditionalExpression::ConditionalExpression(ConditionalExpression &other): logicalOperators(other.logicalOperators) {
    conditions=std::move(other.conditions);
}

bool ConditionalExpression::evaluate() {
    bool tempFlag= false;
    auto it = logicalOperators.begin();
    for(auto &condition: conditions){
        if(condition==*conditions.begin()){
            tempFlag=condition->evaluate();
        }
        else {
            switch(*it){
                case ANDSY:
                    tempFlag=tempFlag&&condition->evaluate();
                    break;
                case ORSY:
                    tempFlag=tempFlag||condition->evaluate();
                    break;
                default:break;
            }
            ++it;
        }
    }

    return tempFlag;
}
