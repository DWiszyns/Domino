#include <utility>

//
// Created by dominik on 5/24/19.
//

#include "Node.h"

Node::Node(ValueType myVariable):myVariable(std::move(myVariable)) {

}

Node::~Node() {

}

ValueType Node::getValue() {
    return myVariable;
}
