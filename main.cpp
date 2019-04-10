#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include "Source.h"
#include "Scan.h"

int main(int argc, char *argv[]) {
    std::string word = "";
    if(argc!=3){
        std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }
    std::ifstream we; //
    std::string word = "";
    Source source(argv[2]);
    Scan scan(source);
    SymType retvalue;
    while((retvalue =scan.nextSymbol())!=EOFSY){
        std::cout<<retvalue<<std::endl;
    }
}