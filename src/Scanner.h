//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SCAN_H
#define DOMINO_SCAN_H

#define MAXIDLEN 15

#include <unordered_map>
#include "Source.h"
#include "ScanDef.h"
#include "Token.h"

class Scanner{
    Source &src;
    char c;
    void nextChar() { c=src.nextChar(); }
    int atomLine;
    int atomPos;
    char spell[MAXIDLEN+1];
    static std::unordered_map <std::string, SymbolType> keyWordHashMap;


public:
    Scanner(Source &source);
    ~Scanner();
    virtual Token nextToken();
    void scanError(int ec, std::string word);
    void scanError(SymbolType atom, std::string word);
    Token createString();
    Token createNumber();
    Token getFirstUsefulChar();
    Token createStringInQuotes();
    Token createTwoSignOperator();
    Token createOneSignOperator();
    void flushSpell();
};



#endif //DOMINO_SCAN_H
