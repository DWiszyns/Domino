//
// Created by dominik on 5/26/19.
//

#ifndef DOMINO_ARRAY_H
#define DOMINO_ARRAY_H


#include <string>
#include "Variable.h"

template <typename T>
class Array {
    std::string name;
    const int maxSize;
    Variable<T> *values;
    TypeKind type;
    Array(Array &otherArray):
            name(otherArray.name),maxSize(otherArray.maxSize), type(otherArray.type)
    {
        values = new Variable<T>[maxSize];
        for(int i=0;i<maxSize;++i){
            values[i]=otherArray.values[i];
        }
    }
    Array(std::string name, const int maxSize, TypeKind type):
            name(name), maxSize(maxSize), type(type){
        values = new Variable<T>[maxSize];
    }
    ~Array(){
        delete[] values;
    }

};


#endif //DOMINO_ARRAY_H
