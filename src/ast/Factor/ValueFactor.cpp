//
// Created by dominik on 5/27/19.
//

#include "ValueFactor.h"

Node ValueFactor::calculate() {
    return Factor::getNode();
}

ValueFactor::ValueFactor(Node node):Factor(node){

}

ValueFactor::~ValueFactor() {

}

ValueFactor::ValueFactor(const ValueFactor& otherFactor):Factor(otherFactor.getNode()){

}

ValueFactor::ValueFactor(const Factor &otherFactor) : Factor(otherFactor) {

}

