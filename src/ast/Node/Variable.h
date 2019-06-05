//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_VARIABLE_H
#define DOMINO_VARIABLE_H


#include "Node.h"


class Variable {
    std::string name;
    std::vector<std::shared_ptr<Node>> nodes;
    unsigned int size;
    bool singleNode;

public:
    Variable();
    Variable(const Variable &otherVariable);
    Variable& operator=(const Variable&);
    Variable(std::string name, std::vector<std::shared_ptr<Node>> nodes, unsigned int size);
    Variable(std::string name, unsigned int size, TypeKind type);
    ~Variable();
    auto getValue();
    auto getValueByIndex(unsigned int i);
    Node getNode();
    std::shared_ptr<Node> getNodeReference();
    std::shared_ptr<Node> getNodeReferenceByIndex(int i);
    Node getNodeByIndex(int i);
    void setNodeForIndex(int i,Node node);
    std::string getName();
    bool isSingleNode();
    void setDefaultValues(TypeKind typeKind);
    void setNodeToDefault();

};

#endif //DOMINO_VARIABLE_H
