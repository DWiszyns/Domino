#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "Variable.h"

Variable::Variable() {
        nodes.push_back(std::move(std::make_unique<Node>()));
        singleNode=true;
        name="emptyvariable";
}

Variable::Variable(const Variable &otherVariable) :
        name(otherVariable.name){
    for(const auto &n:otherVariable.nodes)
        nodes.push_back(std::make_unique<Node>(*n));
}

Variable::Variable(std::string name, std::vector<std::shared_ptr<Node>> nodes,unsigned int size):
    name(std::move(name)),nodes(std::move(nodes)),size(size){
    singleNode= size == 1;
}

Variable::~Variable() {

}

auto Variable::getValue() {
    return std::make_unique<Node>(*nodes[0]);
}

auto Variable::getValueByIndex(unsigned int i) {
    return std::make_unique<Node>(*nodes[i]);
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

void Variable::setNodeForIndex(int i,Node node) {
    *nodes[i]= std::move(node);

}

Variable::Variable(std::string name, unsigned int size, TypeKind type):
        name(std::move(name)),size(size){
    std::vector<std::unique_ptr<Node>> nodes;
    singleNode= size == 1;
    setDefaultValues(type);
}

void Variable::setDefaultValues(TypeKind typeKind) {
    switch(typeKind){
        case INT: {
            for (int i = 0; i < size; ++i)
                nodes.push_back(std::make_unique<Node>(0));
            break;
        }
        case FLOAT: {
            for (int i = 0; i < size; ++i)
                nodes.push_back(std::make_unique<Node>(0.1f));
            break;
        }
        case RATIONAL:{
            for(int i=0;i<size;++i)
                nodes.push_back(std::make_unique<Node>(Rational("1.1r")));
            break;
        }
        case CHAR:{
            for(int i=0;i<size;++i)
                nodes.push_back(std::make_unique<Node>('a'));
        }
        case STRING:{
            std::string x ="default";
            for(int i=0;i<size;++i)
                nodes.push_back(std::make_unique<Node>(x));
            break;
        }
        case BOOLEAN:{
            for(int i=0;i<size;++i)
                nodes.push_back(std::make_unique<Node>(true));
            break;
        }
        default:break;
    }

}

std::shared_ptr <Node> Variable::getNodeReference() {
    return nodes[0];
}

std::shared_ptr<Node> Variable::getNodeReferenceByIndex(int i) {
    return nodes[i];
}

void Variable::setNodeToDefault() {
    switch(nodes[0]->getTypeKind()){
        case INT: {
            for (int i = 0; i < size; ++i)
                setNodeForIndex(i,0);
            break;
        }
        case FLOAT: {
            for (int i = 0; i < size; ++i)
                setNodeForIndex(i,0.1f);
            break;
        }
        case RATIONAL:{
            for(int i=0;i<size;++i)
               setNodeForIndex(i,"1.1r");
            break;
        }
        case CHAR:{
            for(int i=0;i<size;++i)
                setNodeForIndex(i,'a');
        }
        case STRING:{
            std::string x ="default";
            for(int i=0;i<size;++i)
                setNodeForIndex(i,x);
            break;
        }
        case BOOLEAN:{
            for(int i=0;i<size;++i)
                setNodeForIndex(i,true);
            break;
        }
        default:break;
    }
}
