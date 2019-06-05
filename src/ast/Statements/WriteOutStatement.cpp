//
// Created by dominik on 5/20/19.
//

#include "WriteOutStatement.h"
#include "../Function.h"
#include <iostream>

void WriteOutStatement::execute() {
    for(auto &i:expressions)
        std::cout<<i->execute();
}

WriteOutStatement::WriteOutStatement(Scope *scope, std::list<std::unique_ptr<Expression>> expressions):Statement(*scope),expressions(std::move(expressions)) {

}

WriteOutStatement::WriteOutStatement(WriteOutStatement &other): Statement(other.scope) {
    expressions=std::move(other.expressions);
}

WriteOutStatement::~WriteOutStatement() {

}
