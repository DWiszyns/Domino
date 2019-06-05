//
// Created by dominik on 5/20/19.
//

#include "Assignment.h"


void Assignment::execute() {
    Statement::execute();
    lvalue->setNodeForIndex(index,rvalue->execute());
}

Assignment::~Assignment() {

}

Assignment::Assignment(Variable* lvalue, std::unique_ptr <Expression> expressionRValue, unsigned int i):
        lvalue(lvalue),rvalue(std::move(expressionRValue)),index(i),Statement() {

}

Assignment::Assignment() {

}

Expression Assignment::getExpression() {
    return *rvalue;
}

bool Assignment::isEmptyVariable() {
    return lvalue->getName()=="emptyvariable";
}

Assignment::Assignment(const Assignment &other):
    lvalue(other.lvalue),index(other.index) {
    rvalue=std::make_unique<Expression>(*other.rvalue);
}


