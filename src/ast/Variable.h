//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_VARIABLE_H
#define DOMINO_VARIABLE_H


#include <string>
#include <memory>
#include "Node/Node.h"

std::string types[7] = { "int","rational",
                         "boolean","float",
                         "string","char","void"};
enum TypeKind{Int, Rational, Boolean,
    Float, String, Char, Void };
//template <typename T>
class Variable {
    std::string name;
    std::unique_ptr<Node> node;
    //std::string value;
//    TypeKind type; //do I really need you?
public:
    Variable(){
        node=std::make_unique<Node>();

    }
    Variable(Variable &otherVariable):
            name(otherVariable.name),node(std::move(otherVariable.node)){
    }
    Variable(std::string name, std::unique_ptr<Node> node):name(name),node(std::move(node)){

    };
    ~Variable(){

    }
    auto getValue(){
        return node->getValue();
    }

};

#endif //DOMINO_VARIABLE_H
