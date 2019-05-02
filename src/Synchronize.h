//
// Created by dominik on 5/2/19.
//

#ifndef DOMINO_SYNCHRONIZE_H
#define DOMINO_SYNCHRONIZE_H


#include "Parser.h"
#include<set>

class Synchronize {
    static Parser *p;
// Synchronizacja na rzecz parsera (*p)
    const std::set <SymbolType> &f;
    void skipto(const std::set <SymbolType> &sset);
public:
    Synchronize(const std::set <SymbolType>& starterset,
                const std::set <SymbolType>& fset);
    ~Synchronize();
};


#endif //DOMINO_SYNCHRONIZE_H
