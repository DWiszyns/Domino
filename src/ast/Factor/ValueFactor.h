//
// Created by dominik on 5/27/19.
//

#ifndef DOMINO_VALUEFACTOR_H
#define DOMINO_VALUEFACTOR_H


#include "Factor.h"

class ValueFactor: public Factor {
public:
    ValueFactor(Node node);
    ~ ValueFactor();
    Node calculate() override;
};


#endif //DOMINO_VALUEFACTOR_H
