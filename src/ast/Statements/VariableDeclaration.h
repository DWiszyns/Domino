//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_VARIABLEDECLARATION_H
#define DOMINO_VARIABLEDECLARATION_H

#include <vector>
#include "Assignment.h"


class VariableDeclaration: public Statement {
    Variable declaredVariable;
public:
    VariableDeclaration(Scope scope, TypeKind whichType, std::string name,Assignment assignment);
    VariableDeclaration(Scope scope, TypeKind whichType, std::string name, unsigned int size);
    VariableDeclaration(VariableDeclaration &other);
    ~VariableDeclaration() override;
    void execute(Scope scope);

};


#endif //DOMINO_VARIABLEDECLARATION_H
