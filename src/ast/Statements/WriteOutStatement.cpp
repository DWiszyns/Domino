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

WriteOutStatement::WriteOutStatement(const WriteOutStatement &other): Statement(other.scope) {
    for(const auto &n: other.expressions)
        expressions.push_back(std::make_unique<Expression>(*n));
}

WriteOutStatement::~WriteOutStatement() {

}
