//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_FUNCTION_H
#define DOMINO_FUNCTION_H


//#include "Variable.h" //watch out might have too many includes
#include<string>

class Function {
    std::string name;
//    TypeKind type;
public:
    //jakis wskaznik na nia?
    Function(std::string name):
            name(name){
    }
    ~Function(){
    }
};


#endif //DOMINO_FUNCTION_H
