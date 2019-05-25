//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_STRINGNODE_H
#define DOMINO_STRINGNODE_H

#include <string>
#include "Node.h"

class StringNode: public Node {
    std::string value;
public:
    StringNode(std::string value="1.5r");
    ~StringNode();
    std::string getValue();

};


#endif //DOMINO_STRINGNODE_H
