//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_FACTOR_H
#define DOMINO_FACTOR_H

#include "../Node/Node.h"

class Factor {
protected:
    std::shared_ptr<Node> node;
public:
    explicit Factor();
    Factor& operator=(const Factor&) = delete;
    Factor(std::shared_ptr<Node> node);
    Factor(const Factor &otherFactor);
    ~Factor()= default;
    virtual Node calculate();
    Node getNode() const;

};


#endif //DOMINO_FACTOR_H
