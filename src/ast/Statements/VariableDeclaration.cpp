#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "VariableDeclaration.h"
#include "../Function.h"

VariableDeclaration::~VariableDeclaration() {

}

VariableDeclaration::VariableDeclaration(Scope scope, TypeKind whichType, std::string name, Assignment assignment):
    Statement(scope), declaredVariable(std::move(name),1,whichType){
    assignment.execute();
    scope.addVariable(declaredVariable);
}

void VariableDeclaration::execute(Scope scope) {
       // scope.addVariable(declaredVariable);
}

VariableDeclaration::VariableDeclaration(Scope scope, TypeKind whichType, std::string name, unsigned int size):
        Statement(scope), declaredVariable(std::move(name),size,whichType){
    scope.addVariable(declaredVariable);

}

VariableDeclaration::VariableDeclaration(VariableDeclaration &other) {

}



