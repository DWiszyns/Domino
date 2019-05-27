//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_FACTOR_H
#define DOMINO_FACTOR_H

#include "../Node/Node.h"

class Factor {
    Node node;
public:
    Factor(Node node);
    ~Factor();
    virtual Node calculate();
    Node getNode();

};


#endif //DOMINO_FACTOR_H
