//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_PROGRAM_H
#define DOMINO_PROGRAM_H


#include "MainFunction.h"
#include "Function.h"
#include <list>

class Program {
    //std::list<Function> functions;
    MainFunction mainFunction;
    int a,b;

public:
    Program(MainFunction mainFunction);
    ~Program();
    void execute();

};


#endif //DOMINO_PROGRAM_H
