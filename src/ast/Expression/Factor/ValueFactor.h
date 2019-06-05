//
// Created by dominik on 5/27/19.
//

#ifndef DOMINO_VALUEFACTOR_H
#define DOMINO_VALUEFACTOR_H


#include "Factor.h"

class ValueFactor: public Factor {
public:
    explicit ValueFactor(std::shared_ptr<Node> node);
    ValueFactor(const ValueFactor& otherFactor);
    explicit ValueFactor(const Factor& otherFactor);
    ~ ValueFactor();
    Node calculate() override;
};


#endif //DOMINO_VALUEFACTOR_H
