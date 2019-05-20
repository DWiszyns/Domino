//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_MAINFUNCTION_H
#define DOMINO_MAINFUNCTION_H

#include<list>
#include "Function.h"
#include "Content.h"

class MainFunction {
    //TODO parameters
    std::list<Function> functions;
    Content content;

public:
    MainFunction();
    ~MainFunction();
    void execute(std::list<Function> &functions);

};


#endif //DOMINO_MAINFUNCTION_H
