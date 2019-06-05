//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_WRITEOUTSTATEMENT_H
#define DOMINO_WRITEOUTSTATEMENT_H


#include "Statement.h"
#include "../Expression/Expression.h"

class WriteOutStatement : public Statement{
    std::list <std::unique_ptr<Expression>> expressions;
public:
    WriteOutStatement()= default;
    WriteOutStatement(Scope *scope,std::list <std::unique_ptr<Expression>> expressions);
    WriteOutStatement(WriteOutStatement &other);
    ~WriteOutStatement() override;
    void execute();
};


#endif //DOMINO_WRITEOUTSTATEMENT_H
