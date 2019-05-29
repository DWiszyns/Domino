//
// Created by dominik on 5/20/19.
//

#include "Assignment.h"


void Assignment::execute() {
    //lvalue=rvalue.execute(); //lvalue.setNode(rvalue.execute); setNode na kopii nie na adresie wazne, ktory index
    Statement::execute();
    lvalue->setNodeForIndex(index,rvalue.execute());
}

Assignment::~Assignment() {

}
/*
Assignment::Assignment(std::unique_ptr<Variable> lvalue, std::unique_ptr <Expression> expressionRValue, unsigned int i):
    lvalue(std::move(lvalue)),rvalue(*expressionRValue),index(i),Statement() {

}
*/
Assignment::Assignment(Variable* lvalue, std::unique_ptr <Expression> expressionRValue, unsigned int i):
        lvalue(lvalue),rvalue(*expressionRValue),index(i),Statement() {

}


