//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_FLOATNODE_H
#define DOMINO_FLOATNODE_H


#include "Node.h"

class FloatNode: public Node {
    float value;
public:
    FloatNode(float value=1.5f);
    ~FloatNode();
    float getValue();

};


#endif //DOMINO_FLOATNODE_H
