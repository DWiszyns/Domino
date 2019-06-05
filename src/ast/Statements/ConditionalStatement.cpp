//
// Created by dominik on 5/20/19.
//

#include "ConditionalStatement.h"
#include "../Function.h"

ConditionalStatement::ConditionalStatement() {

}

ConditionalStatement::ConditionalStatement(Scope currScope,std::unique_ptr<ConditionalExpression> condition, Content content):scope(currScope),
                                                                                                             conditionalExpression(std::move(condition)),content(content){

}
ConditionalStatement::ConditionalStatement(Scope *oldScope,std::unique_ptr<ConditionalExpression> condition, Content content):scope(oldScope),
                        conditionalExpression(std::move(condition)),content(content){

}

ConditionalStatement::ConditionalStatement(ConditionalStatement &other):scope(other.scope),
    conditionalExpression(std::move(other.conditionalExpression)),content(other.content){

}

void ConditionalStatement::execute() {
    if(conditionalExpression->evaluate()){
        content.execute();
    }
}
