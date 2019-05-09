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
    if(argc!=3){
        std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }
    Source source(argv[2]);
    Scanner scan(source);
    Parser parser(scan);
    parser.program();
    /*std::fstream input("../../src/test3.tkom");
    input.open("../../src/test3.tkom",std::fstream::in);
    std::string ex = "Example";
    std::stringstream x;
    std::ifstream    f;
    x<<input.rdbuf();
    std::cout<<x.str();
    x<<ex;
    std::cout<<x.str();
    char c;
    x.get(c);
    std::cout<<c;*/

}