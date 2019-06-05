#include <utility>

#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "VariableDeclaration.h"
#include "../Function.h"

VariableDeclaration::~VariableDeclaration() {

}

VariableDeclaration::VariableDeclaration(Scope *scope, TypeKind whichType, std::string name, std::unique_ptr<Assignment> assignment):
    Statement(*scope), assignment(std::move(assignment)){
    std::unique_ptr<Variable> tempVariable=std::make_unique<Variable>(std::move(name),1,whichType);
    declaredVariable=tempVariable.get();
    scope->addVariable(std::move(tempVariable));
}

void VariableDeclaration::execute() {
   if(!assignment->isEmptyVariable()) assignment->execute();

}

VariableDeclaration::VariableDeclaration(Scope *scope, TypeKind whichType, std::string name, unsigned int size):
        Statement(*scope){
    std::unique_ptr<Variable> tempVariable=std::make_unique<Variable>(std::move(name),size,whichType);
    declaredVariable=tempVariable.get();
    scope->addVariable(std::move(tempVariable));

}

VariableDeclaration::VariableDeclaration(VariableDeclaration &other):Statement(other.scope), declaredVariable(other.declaredVariable){
    assignment = std::move(other.assignment);

}

VariableDeclaration::VariableDeclaration(Scope *scope, std::unique_ptr<Variable> variable, std::unique_ptr<Assignment> assignment):Statement(*scope),
        declaredVariable(variable.get()),assignment(std::move(assignment)) {
    scope->addVariable(std::move(variable));
    //assignment.execute();
}



