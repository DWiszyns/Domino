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

class t1{
public:
    t1() = default;

    virtual void execute(){
        std::cout<<1<<std::endl;
    }
};
class t2: public  t1{
public:
    t2() = default;

    void execute(){
        std::cout<<2<<std::endl;
    }
};
class t3: public t1{
public:
    t3() = default;

    void execute(){
        std::cout<<3<<std::endl;
    }
};
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