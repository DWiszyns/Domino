#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include "Source.h"
#include "Scanner.h"
#include "Parser.h"

int main(int argc, char *argv[]) {
    /*if(argc!=3){
        std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }*/
    //Source source(argv[2]);
    Source source("test3.tkom");
    Scanner scan(source);
    Parser parser(scan);
    parser.program();
}