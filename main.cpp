#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include "Source.h"
#include "Scan.h"

int main(int argc, char *argv[]) {
    float arg = 1.5f;
    std::cout<<STRINGCONST<<std::endl;
    if(argc!=3){
        std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }
    /*std::cout<<argv[2]<<std::endl;
    std::ifstream we; //
    we.open(argv[2],std::ios::in);
    std::string word;
    if(we.is_open())
    {
        char c;
        we.get(c);
        std::cout << c;
        std::cout.flush();
        while(!we.eof()) {
            std::cout << c;
            we.get(c);
        }
    }
    we.close();*/
    Source source(argv[2]);
    Scan scan(source);
    SymType retvalue;
    while((retvalue =scan.nextSymbol())!=EOFSY){
        std::cout<<retvalue<<std::endl;
    }
}