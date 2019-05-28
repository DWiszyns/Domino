//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_VARIABLE_H
#define DOMINO_VARIABLE_H


#include <string>
#include <memory>
#include <vector>
#include "Node/Node.h"


class Variable {
    std::string name;
    std::vector<std::unique_ptr<Node>> nodes;
    unsigned int size;
    bool singleNode;//tells us if we can access it with []
    //std::string value;
//    TypeKind type; //do I really need you?
public:
    Variable();
    Variable(const Variable &otherVariable);
    Variable& operator=(const Variable&);
    Variable(std::string name, std::vector<std::unique_ptr<Node>> nodes, unsigned int size);
    ~Variable();
    auto getValue();
    auto getValueByIndex(unsigned int i);
    Node getNode();
    Node getNodeByIndex(int i);
    std::string getName();
    bool isSingleNode();

};

#endif //DOMINO_VARIABLE_H
