#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include "Source.h"
#include "Scanner.h"
#include "Parser.h"
#include "Synchronize.h"

int main(int argc, char *argv[]) {
    float arg = 1.5f;
    std::cout<<STRINGCONST<<std::endl;
    if(argc!=3){
        std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }
    /*SymbolType signSymbols[]={SUBTRACTSY, ADDSY};
    std::set<SymbolType> signs;
    signs.insert(signSymbols,signSymbols+2);
    SymbolType statementValueSymbols[] = {IDENTIFIER,INTCONST,CHARCONST,OROUNDBRACKET};
    std::set<SymbolType>statementValue;
    statementValue.insert(statementValueSymbols,statementValueSymbols+4);
    std::set<SymbolType> temp;
    std::set_union(statementValue.begin(),statementValue.end(),signs.begin(),
                   signs.end(),std::inserter(temp,std::begin(temp)));*/
    Source source(argv[2]);
    Scanner scan(source);
    SymbolType retvalue;
    while((retvalue =scan.nextSymbol())!=EOFSY){
        std::cout<<retvalue<<std::endl;
    }
    /*
    Parser* Synchronize::p;
    Source in(argv[2]);
    Scanner scan(in);
    Parser par(scan);
    Synchronize::p = &par;
    par.program();
    return 0;*/
}