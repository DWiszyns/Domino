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
#include "Scope.h"
#include "ast/Program.h"

void execute(Program& program){
    std::cout<<program.execute()<<std::endl;
}
int main(int argc, char *argv[]) {
    
    /*if(argc!=3){
        std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }*/
    Source source(argv[2]);
    //Source source("test1.tkom");
    Scanner scan(source);
    Parser parser(scan);
    execute(*parser.parse());
    //Scope scope;
    //std::cout<<scope.types[0];
}