//
// Created by dominik on 5/20/19.
//

#include "Variable.h"

Variable::Variable() {
        nodes.push_back(std::move(std::make_unique<Node>()));
        singleNode=true;
}

Variable::Variable(const Variable &otherVariable) :
        name(otherVariable.name){
    nodes.reserve(otherVariable.nodes.size());
    for(const auto &n:otherVariable.nodes)
        nodes.push_back(std::make_unique<Node>(*n));
}

Variable::Variable(std::string name, std::vector<std::unique_ptr<Node>> nodes,unsigned int size):
    name(std::move(name)),nodes(std::move(nodes)),size(size){
    if(size==1){
        singleNode=true;
    }
    else singleNode=false;

}

Variable::~Variable() {

}

auto Variable::getValue() {
    return 0;//nodes[0]->getValue();
}

auto Variable::getValueByIndex(unsigned int i) {
    return 0;//nodes[i]->getValue();
}

std::string Variable::getName() {
    return name;
}

bool Variable::isSingleNode() {
    return singleNode;
}

Node Variable::getNode() {
    return *nodes[0];
}

Node Variable::getNodeByIndex(int i) {
    return *nodes[i];
}

Variable &Variable::operator=(const Variable &otherVariable){
    if (this != &otherVariable) {
        this->name=otherVariable.name;
        for(const auto &n:otherVariable.nodes)
            nodes.push_back(std::make_unique<Node>(*n));
    }
    return *this;
}


