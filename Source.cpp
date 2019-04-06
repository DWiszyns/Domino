//
// Created by dominik on 4/6/19.
//

#include "Source.h"
#include <fstream>
#include <iostream>


Source::Source(std::string source):source(source) {
    tLine=0;
    tPos=0;
    errorInLine=0;
    errorTotal=0;
    std::ifstream we; //otwarcie pliku wejsciowego
    we.open(source,std::fstream::in);
    if(!we.is_open())
    {
        std::cout<<"Fatal error can't open source file"<<std::endl;
    }
    std::cout<<"Domino v.0.1 2019"<<std::endl;
}

Source::~Source() {
    we.close();
}

void Source::Error() {
}

int Source::nextChar() {
    return 0;
}

int Source::nextString() {
    return 0;
}
