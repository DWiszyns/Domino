//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_FACTOR_H
#define DOMINO_FACTOR_H

#include "../Node/Node.h"

class Factor {
    Node node;
public:
    explicit Factor();
    Factor& operator=(const Factor&) = delete;
    Factor(Node node);
    Factor(const Factor &otherFactor);
    ~Factor()= default;
    virtual Node calculate();
    Node getNode() const;

};


#endif //DOMINO_FACTOR_H
