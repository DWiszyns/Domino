//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_VARIABLEDECLARATION_H
#define DOMINO_VARIABLEDECLARATION_H


#include "Assignment.h"

class VariableDeclaration: public Statement {
public:
    VariableDeclaration(Scope scope, int whichType, std::string name,Assignment assignment);
    ~VariableDeclaration() override;
    void execute(Scope scope);

};


#endif //DOMINO_VARIABLEDECLARATION_H
