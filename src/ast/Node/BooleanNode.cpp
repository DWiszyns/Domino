//
// Created by dominik on 5/24/19.
//

#include "BooleanNode.h"

bool BooleanNode::getValue() {
    return booleanValue;
}

BooleanNode::BooleanNode(bool booleanValue):booleanValue(booleanValue) {
}

BooleanNode::~BooleanNode() {

}
