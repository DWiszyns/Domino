//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_CONTENT_H
#define DOMINO_CONTENT_H

#include <list>


#include "Statements/Statement.h"
#include "Statements/VariableDeclaration.h"


class Content {
   Scope *scope;
    std::list<std::unique_ptr<Statement>> statements;
public:
    Content();
    Content(std::list<std::unique_ptr<Statement>> statements ,Scope *scope);
    Content(Content &otherContent);
    Content(const Content &otherContent);
    ~Content();
    Scope getScope();
    void setScope(Scope scope);
    void execute();

};


#endif //DOMINO_CONTENT_H
