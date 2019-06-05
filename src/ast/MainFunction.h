//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_MAINFUNCTION_H
#define DOMINO_MAINFUNCTION_H

#include<list>
#include "Function.h"

class MainFunction {
    //std::list<Function> functions;
    Content content;

public:
    MainFunction();
    MainFunction(Content content);
    ~MainFunction();
    Content getContent();
    void execute();

};


#endif //DOMINO_MAINFUNCTION_H
