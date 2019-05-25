//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_RATIONALNODE_H
#define DOMINO_RATIONALNODE_H


#include "Node.h"
#include "../../Rational.h"

class RationalNode: public Node {
    Rational value;
public:
    RationalNode(Rational value="1.5r");
    ~RationalNode();
    Rational getValue();

};


#endif //DOMINO_RATIONALNODE_H
