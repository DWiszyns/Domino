//
// Created by dominik on 5/20/19.
//

#include "Factor.h"
//
Node Factor::getNode() const{
    return *node;
}

Factor::Factor(std::shared_ptr<Node> node):node(std::move(node)) {

}

Factor::Factor(const Factor &otherFactor) {
    node=std::make_shared<Node>(*otherFactor.node);
}

Factor::Factor() {

}

Node Factor::calculate() {
    return 0;
}
