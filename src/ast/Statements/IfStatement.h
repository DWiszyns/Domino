//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_IFSTATEMENT_H
#define DOMINO_IFSTATEMENT_H

#include "ConditionalStatement.h"
#include "../ConditionalExpression.h"
#include "../Content.h"

class IfStatement:public ConditionalStatement{
public:
    IfStatement();
    IfStatement(Scope *oldScope,std::unique_ptr<ConditionalExpression> conditionalExpression, Content content);
    IfStatement(IfStatement& ifStatement);
    ~IfStatement()=default;
    void execute() override;
};


#endif //DOMINO_IFSTATEMENT_H
