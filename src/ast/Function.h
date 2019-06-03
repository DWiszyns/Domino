//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_FUNCTION_H
#define DOMINO_FUNCTION_H


//#include "Variable.h" //watch out might have too many includes
#include<string>
#include "Node/Value.h"
#include "ParametersDefinition.h"
#include "Content.h"


class Function {
    std::string name;
    TypeKind type;
    ParametersDefinition parameters;
    Content content;//probably needs to be static
public:
    Function();
    Function(Function &otherFunction);
    Function(const Function &otherFunction);
    Function(std::string name,TypeKind type, ParametersDefinition parameters, Content content);
    ~Function()= default;
    Node callFunction();

};


#endif //DOMINO_FUNCTION_H
