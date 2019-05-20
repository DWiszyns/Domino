//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_SCOPE_H
#define DOMINO_SCOPE_H

#include <iostream>
#include <list>
#include "Parser.h"
#include "ScanDef.h"

class Scope {
    Scope *externalScope;
    //Parser parser; //tego nie jestem pewien
    std::string types[7] = { "int","rational",
                             "boolean","float",
                             "string","char","void"};
    enum TypeKind{Int, Rational, Boolean,
        Float, String, Char, Void };
    struct Variable{
        std::string name;
        std::string value;
        TypeKind type;
        Variable(Variable &otherVariable):
                name(otherVariable.name),value(otherVariable.value), type(otherVariable.type){
        }
        Variable(std::string name, std::string value, TypeKind type):
        name(name),value(value), type(type){
        }
    };
    struct Array{
        std::string name;
        const int maxSize;
        std::string *values;
        TypeKind type;
        Array(Array &otherArray):
        name(otherArray.name),maxSize(otherArray.maxSize), type(otherArray.type)
        {
            values = new std::string[maxSize];
            for(int i=0;i<maxSize;++i){
                values[i]=otherArray.values[i];
            }
        }
        Array(std::string name, const int maxSize, TypeKind type):
        name(name), maxSize(maxSize), type(type){
            values = new std::string[maxSize];
        }
        ~Array(){
            delete[] values;
        }
    };
    struct Function{
        std::string name;
        TypeKind type;

        //jakis wskaznik na nia?
        Function(std::string name, TypeKind type):
        name(name), type(type){
        }
        ~Function(){
        }

    };


    std::list<Variable> variables;
    std::list <Array> arrays;
    std::list <Function> functions;

public:
    Scope(Scope *ext, std::list<Variable> variables, std::list <Array> arrays,std::list <Function> functions);
    ~Scope();
    //lista array, zmiennych i funkcji
};


#endif //DOMINO_SCOPE_H
