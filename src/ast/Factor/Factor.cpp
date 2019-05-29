//
// Created by dominik on 5/20/19.
//

#include "Factor.h"

Node Factor::getNode() const{
    return node;
}

Factor::Factor(Node node):node(node) {

}

Factor::Factor(const Factor &otherFactor):node(otherFactor.getNode()) {

}

Factor::Factor() {

}
