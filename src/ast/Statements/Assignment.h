//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_ASSIGNMENT_H
#define DOMINO_ASSIGNMENT_H


#include "../Variable.h"
#include "../Statement.h"
#include "../Expression.h"

class Assignment:public Statement {
    std::unique_ptr<Variable> lvalue;
    Expression rvalue;
    unsigned int index;
public:
    Assignment(std::unique_ptr<Variable> lvalue, std::unique_ptr <Expression> rvalue,unsigned int i=0);//czy jest mi tu potrzebny Scope???
    //mozna sprawdzic czy zmienna nalezy do Scope'a, ale czy tego nie powininem sprawdzic w parserze??
    ~Assignment() override;
    void execute() override;

};


#endif //DOMINO_ASSIGNMENT_H
