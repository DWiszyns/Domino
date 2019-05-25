//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_CHARNODE_H
#define DOMINO_CHARNODE_H


#include "Node.h"

class CharNode: public Node {
    char value;
public:
    CharNode(char value='c');
    ~CharNode();
    char getValue();

};


#endif //DOMINO_CHARNODE_H
