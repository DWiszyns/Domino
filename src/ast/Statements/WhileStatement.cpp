//
// Created by dominik on 5/20/19.
//

#include "WhileStatement.h"
#include "../Function.h"

WhileStatement::WhileStatement() {

}

WhileStatement::WhileStatement(std::unique_ptr<ConditionalExpression> conditionalExpression,
                               Content content):ConditionalStatement(std::move(conditionalExpression),content) {

}

WhileStatement::WhileStatement(WhileStatement &other):ConditionalStatement(std::move(other.conditionalExpression),
            other.content){

}

void WhileStatement::execute() {
    while(conditionalExpression->evaluate())
        ConditionalStatement::execute();
        scope.setToDefault();
}

WhileStatement::~WhileStatement() {

}
