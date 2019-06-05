//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_IFSTATEMENT_H
#define DOMINO_IFSTATEMENT_H

#include "ConditionalStatement.h"
#include "../ConditionalExpression.h"
#include "../Content.h"

class IfStatement:public ConditionalStatement{
    std::vector<std::unique_ptr<ConditionalExpression>> conditionalExpressions;
    std::list<Content> contents;
public:
    IfStatement();
    IfStatement(std::vector<std::unique_ptr<ConditionalExpression>> conditionalExpressions,std::list<Content> contents);
    IfStatement(Scope *oldScope,std::list<std::unique_ptr<ConditionalExpression>> conditionalExpression, std::list<Content> contents);
    IfStatement(IfStatement& ifStatement);
    ~IfStatement()=default;
    void execute() override;
};


#endif //DOMINO_IFSTATEMENT_H
