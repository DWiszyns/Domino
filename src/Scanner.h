//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SCAN_H
#define DOMINO_SCAN_H

#define MAXIDLEN 15
#define NKEYS 17

#include <unordered_map>
#include "Source.h"
#include "ScanDef.h"

class Scanner
        {
    Source &src;
    char c;
    void nextChar() { c=src.nextChar(); }
    int atomLine;     //mozna by
    int atomPos;
    char    spell[MAXIDLEN+1];// Ostatni ident
    static std::unordered_map <std::string, SymbolType > keyWordHashMap;


public:
    Scanner(Source &source);
    ~Scanner();
    SymbolType nextSymbol();
    void scanError(int ec, std::string word);
    void scanError(SymbolType atom, std::string word);
};



#endif //DOMINO_SCAN_H
