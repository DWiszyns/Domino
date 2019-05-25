//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_BOOLEANNODE_H
#define DOMINO_BOOLEANNODE_H


#include "Node.h"

class BooleanNode: public Node {
    bool booleanValue;
public:
     BooleanNode(bool booleanValue);
     ~BooleanNode();
     bool getValue();
};


#endif //DOMINO_BOOLEANNODE_H
