//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_TOKEN_H
#define DOMINO_TOKEN_H

#include <string>
#include "ScanDef.h"

class Token {
    SymbolType tokenType;
    std::string value;
public:
    Token(SymbolType tokenType,std::string value);
    ~Token();
    friend std::ostream& operator<<(std::ostream &os,Token token);
    std::string getValue();
    SymbolType getType();

};


#endif //DOMINO_TOKEN_H
