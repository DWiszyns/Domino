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

class Scan {
    Source &src;
    char c;
    struct KeyRec    // Deskryptor
    {
        char *kw;      // keyword
        SymType atom;  // Odpowiadający mu atom
    };
    void nextC() { c=src.nextChar(); }
    int atomLine;     //Pozycja atomu w tekscie
    int atomPos;
    char    spell[MAXIDLEN+1];// Ostatni ident
    static std::unordered_map <std::string, SymType > KT;


public:
    Scan(Source &source);
    ~Scan();
    SymType nextSymbol();
    void scanError(int ec, std::string word);


};



#endif //DOMINO_SCAN_H
