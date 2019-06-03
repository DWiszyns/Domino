//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_PROGRAM_H
#define DOMINO_PROGRAM_H


#include "MainFunction.h"
#include "Function.h"
#include <list>

class Program {
    std::list<Function> functions;
    MainFunction mainFunction;
    int a,b;

public:
    Program(int a, int b);
    Program(MainFunction mainFunction);
    ~Program();
    int execute();

};


#endif //DOMINO_PROGRAM_H
