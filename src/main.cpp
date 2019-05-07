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

int main(int argc, char *argv[]) {
    float arg = 1.5f;
    std::cout<<STRINGCONST<<std::endl;
    if(argc!=3){
        std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }
    Source source(argv[2]);
    Scanner scan(source);
    SymbolType retvalue;
    Parser parser(scan);
    parser.program();
}