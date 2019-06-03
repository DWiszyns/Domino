#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "Function.h"
#include "Content.h"


Function::Function(std::string name, TypeKind type, ParametersDefinition parameters, Content content):
    name(std::move(name)),type(type),content(std::move(content)),parameters(parameters){

}

Node Function::callFunction() {
    //TODO get parameters, check parameters, give parameters to content
   // return content.execute();
}

Function::Function() {

}

Function::Function(Function &otherFunction):
    parameters(otherFunction.parameters), content(std::move(otherFunction.content)), type(otherFunction.type),name(otherFunction.name){

}

Function::Function(const Function &otherFunction):parameters(otherFunction.parameters), content(std::move(otherFunction.content)), type(otherFunction.type),name(otherFunction.name) {

}

