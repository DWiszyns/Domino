//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_CONDITIONALSTATEMENT_H
#define DOMINO_CONDITIONALSTATEMENT_H


#include "../ConditionalExpression.h"
#include "Statement.h"
#include "../Content.h"

class ConditionalStatement: public Statement {
protected:
    std::unique_ptr<ConditionalExpression> conditionalExpression;
    Content content;
    Scope scope;//do I need you?
public:
    ConditionalStatement();
    ConditionalStatement(Scope *oldScope,std::unique_ptr<ConditionalExpression> conditionalExpression, Content content);
    ConditionalStatement(Scope currScope,std::unique_ptr<ConditionalExpression> condition, Content content);
    ConditionalStatement(ConditionalStatement& conditionalStatement);
    ~ConditionalStatement()=default;
    void execute() override;


};


#endif //DOMINO_CONDITIONALSTATEMENT_H
