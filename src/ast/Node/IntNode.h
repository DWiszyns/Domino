//
// Created by dominik on 5/25/19.
//

#ifndef DOMINO_INTNODE_H
#define DOMINO_INTNODE_H


#include "Node.h"

class IntNode: public Node {
    int value;
public:
    IntNode(int value=0);
    ~IntNode();
    int getValue();

};


#endif //DOMINO_INTNODE_H
