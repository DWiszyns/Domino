//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_WHILESTATEMENT_H
#define DOMINO_WHILESTATEMENT_H


#include "ConditionalStatement.h"

class WhileStatement:public ConditionalStatement {
public:
    WhileStatement();
    WhileStatement(std::unique_ptr<ConditionalExpression> conditionalExpression,Content content);
    WhileStatement(WhileStatement& other);
    ~WhileStatement() override;
    void execute() override;

};


#endif //DOMINO_WHILESTATEMENT_H
