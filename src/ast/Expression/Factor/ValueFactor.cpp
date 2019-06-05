#include <utility>

//
// Created by dominik on 5/27/19.
//

#include "ValueFactor.h"

Node ValueFactor::calculate() {
    return Factor::getNode();
}

ValueFactor::ValueFactor(std::shared_ptr<Node> node):Factor(std::move(node)){

}

ValueFactor::~ValueFactor() {

}

ValueFactor::ValueFactor(const ValueFactor& otherFactor):Factor(otherFactor.node){

}

ValueFactor::ValueFactor(const Factor &otherFactor) : Factor(otherFactor) {

}

