//
// Created by dominik on 5/20/19.
//

#include "Variable.h"

Variable::Variable() {
        nodes.push_back(std::make_unique<Node>());
        singleNode=true;
}

Variable::Variable(Variable &otherVariable) :
        name(otherVariable.name),nodes(std::move(otherVariable.nodes)){
}

Variable::Variable(std::string name, std::vector<std::unique_ptr<Node>> nodes,unsigned int size):
    name(name),nodes(std::move(nodes)),size(size){
    if(size==1){
        singleNode=true;
    }
    else singleNode=false;

}

Variable::~Variable() {

}

auto Variable::getValue() {
    return nodes[0]->getValue();
}

auto Variable::getValueByIndex(unsigned int i) {
    return nodes[i]->getValue();
}

std::string Variable::getName() {
    return name;
}

bool Variable::isSingleNode() {
    return singleNode;
}
