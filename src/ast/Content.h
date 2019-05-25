//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_CONTENT_H
#define DOMINO_CONTENT_H

#include <list>

#include "Function.h"
//#include "../Scope.h"
#include "Statement.h"

class Content {
   // Scope scope;
    std::list <Statement> statements;
public:
    Content();
 //   Content(/*Scope &scope*/);
    ~Content();
    void execute(std::list<Function> functions);
    void addStatement(Statement statement);



};


#endif //DOMINO_CONTENT_H
