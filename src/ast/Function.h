//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_FUNCTION_H
#define DOMINO_FUNCTION_H


#include "Variable.h" //watch out might have too many includes

class Function {
    std::string name;
    TypeKind type;
public:
    //jakis wskaznik na nia?
    Function(std::string name, TypeKind type):
            name(name), type(type){
    }
    ~Function(){
    }
};


#endif //DOMINO_FUNCTION_H
