//
// Created by dominik on 5/20/19.
//

#include "VariableDeclaration.h"

VariableDeclaration::~VariableDeclaration() {

}

VariableDeclaration::VariableDeclaration(Scope scope, int whichType, std::string name, Assignment assignment):Statement(scope) {

}

void VariableDeclaration::execute(Scope scope) {

}