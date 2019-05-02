//
// Created by dominik on 5/2/19.
//

#include "Synchronize.h"

Synchronize::Synchronize(const std::set<SymbolType> &starterset, const std::set<SymbolType> &fset):f(fset) {
    if(!starterset.find(p->symbol))
    {
        p->syntaxError1(p->symbol);
// Nieoczekiwany atom
        skipto(starterset+f);
    }
    p->can_parse = starterset.find(p->symbol);

}

Synchronize::~Synchronize() {
        if(!f.find(p->symbol))
        { p->syntaxError1(p->symbol);
// Nieoczekiwany atom
            skipto(f);
        }

}

void Synchronize::skipto(const std::set<SymbolType> &sset) {

}
