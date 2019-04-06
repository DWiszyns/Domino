//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SCAN_H
#define DOMINO_SCAN_H


#include "Source.h"

class Scan {
    Source src;
public:
    Scan();
    Symtype nextSymbol();
    scanError();
    char nextChar();


};



#endif //DOMINO_SCAN_H
