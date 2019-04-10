//
// Created by dominik on 4/6/19.
//

#include "Source.h"
#include <fstream>
#include <iostream>
#include <iomanip>


Source::Source(std::string source):source(source) {
    textLine=0;
    textPos=0;
    inWordPos=0;
    errorTotal=0;
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

void Source::Error(std::string word, int atomLine, int atomPos, std::string errorLabel) {
    errorTotal++;
    std::cout<<"Error "<<errorLabel<<" in "<<atomLine<<':'<<atomPos<<"around "<<word;

}

char Source::nextChar() {
    int r=1;
    if(textLine==0) r=nextString();  // Pierwszy wiersz
    else if(!word[inWordPos]) r=nextString();
    if(r) return word[inWordPos++];
    else return EOF;
}

int Source::nextString() {
    if(we >> std::noskipws >> word) return 0;    // EOF
    if(word=="\n") {
        ++textLine;
        textPos = 0;
    }
    return 1;
}

int Source::getTextLine() {
    return textLine;
}

int Source::getTextPos() {
    return textPos;
}
