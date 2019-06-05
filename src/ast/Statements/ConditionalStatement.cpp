//
// Created by dominik on 5/20/19.
//

#include "ConditionalStatement.h"
#include "../Function.h"

ConditionalStatement::ConditionalStatement() = default;

//ConditionalStatement::ConditionalStatement(Scope currScope,std::unique_ptr<ConditionalExpression> condition, Content content):scope(currScope),
//                                                                                                             conditionalExpression(std::move(condition)),content(content){
//
//}
//ConditionalStatement::ConditionalStatement(Scope *oldScope,std::unique_ptr<ConditionalExpression> condition, Content content):scope(oldScope),
//                        conditionalExpression(std::move(condition)),content(content){
//
//}

ConditionalStatement::ConditionalStatement(ConditionalStatement &other):
    conditionalExpression(std::move(other.conditionalExpression)),content(other.content),scope(other.content.getScope()){

}

void ConditionalStatement::execute() {
    content.execute();
}

ConditionalStatement::ConditionalStatement(std::unique_ptr<ConditionalExpression> condition, Content content):
    conditionalExpression(std::move(condition)),content(content),scope(content.getScope()) {

}
