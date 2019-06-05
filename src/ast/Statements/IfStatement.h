//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_IFSTATEMENT_H
#define DOMINO_IFSTATEMENT_H

#include "ConditionalStatement.h"
#include "../Expression/ConditionalExpression.h"
#include "../Content.h"

class IfStatement:public Statement{
    std::vector<std::unique_ptr<ConditionalExpression>> conditionalExpressions;
    std::list<Content> contents;
public:
    IfStatement();
    IfStatement(std::vector<std::unique_ptr<ConditionalExpression>> conditionalExpressions,std::list<Content> contents);
//    IfStatement(Scope *oldScope,std::list<std::unique_ptr<ConditionalExpression>> conditionalExpression, std::list<Content> contents);
    IfStatement(IfStatement& ifStatement);
    ~IfStatement();
    void execute() override;
};


#endif //DOMINO_IFSTATEMENT_H
