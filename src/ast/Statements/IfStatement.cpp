//
// Created by dominik on 5/20/19.
//

#include "IfStatement.h"
#include "../Function.h"

IfStatement::IfStatement():Statement(){

}
/*
IfStatement::IfStatement(Scope *oldScope, std::unique_ptr<ConditionalExpression> conditionalExpression, Content content)
        : ConditionalStatement(oldScope, std::move(conditionalExpression), content) {

}
*/
IfStatement::IfStatement(IfStatement &other):conditionalExpressions(std::move(other.conditionalExpressions)),
    contents(std::move(other.contents)){

}

void IfStatement::execute() {
    //ConditionalStatement::execute();
    int j=0;
    for(auto &i: contents) {
        if(conditionalExpressions[j]!= nullptr) {
            if (conditionalExpressions[j]->evaluate()) {
                i.execute();
                break;
            }
            ++j;
        } else i.execute();
    }
}

IfStatement::IfStatement(std::vector<std::unique_ptr<ConditionalExpression>> conditionalExpressions,
                         std::list<Content> contents):conditionalExpressions(std::move(conditionalExpressions)),
                         contents(std::move(contents)){

}

IfStatement::~IfStatement() {
}

