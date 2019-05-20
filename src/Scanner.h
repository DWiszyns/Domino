//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SCAN_H
#define DOMINO_SCAN_H

#define MAXIDLEN 15

#include <unordered_map>
#include "Source.h"
#include "ScanDef.h"

class Scanner
        {
    Source &src;
    char c;
    void nextChar() { c=src.nextChar(); }
    int atomLine;
    int atomPos;
    char spell[MAXIDLEN+1];
    static std::unordered_map <std::string, SymbolType > keyWordHashMap;


public:
    Scanner(Source &source);
    ~Scanner();
    bool divide;
    virtual SymbolType nextSymbol();
    void scanError(int ec, std::string word);
    void scanError(SymbolType atom, std::string word);
    SymbolType createString();
    SymbolType createNumber();
    SymbolType getFirstUsefulChar();
    SymbolType createStringInQuotes();
    SymbolType createTwoSignOperator();
    SymbolType createOneSignOperator();
};



#endif //DOMINO_SCAN_H
