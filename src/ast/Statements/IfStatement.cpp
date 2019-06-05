//
// Created by dominik on 5/20/19.
//

#include "IfStatement.h"
#include "../Function.h"

IfStatement::IfStatement():ConditionalStatement(){

}

IfStatement::IfStatement(Scope *oldScope, std::unique_ptr<ConditionalExpression> conditionalExpression, Content content)
        : ConditionalStatement(oldScope, std::move(conditionalExpression), content) {

}

IfStatement::IfStatement(IfStatement &other):ConditionalStatement(other.scope,std::move(other.conditionalExpression),other.content) {

}

void IfStatement::execute() {
    ConditionalStatement::execute();
}

