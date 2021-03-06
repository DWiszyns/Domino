//
// Created by dominik on 4/6/19.
//

#include "Source.h"
#include "ScanDef.h"
#include <fstream>
#include <iostream>
#include <iomanip>



Source::Source(std::string source,bool test):source(source) {
    textLine=1;
    textPos=0;
    errorTotal=0;
    if(!test) {
        input.open(source, std::fstream::in);
        if (!input.is_open()) {
            std::cout << "Fatal error can't open source file" << std::endl;
        }
        fileInput<<input.rdbuf();
        input.close();
        std::cout << "Domino v.0.1 2019" << std::endl;
    }
    else fileInput<<source;
}


Source::~Source() {
}

void Source::error(std::string word, int atomLine, int atomPos, std::string errorLabel) {
    errorTotal++;
    std::cout<<"Error "<<errorLabel<<" in "<<atomLine<<':'<<atomPos<<"around "<<word;

}

void Source::error(std::string message, std::string atom, int atomLine, int atomPos) {
    errorTotal++;
    std::cout<<message<<"\""<<atom<<"\" at "<<atomLine<<" : "<<atomPos<<std::endl;
}

char Source::nextChar() {
    fileInput.get(c);
    ++textPos;
    if(c=='\n') {
        ++textLine;
        textPos = 0;
    }
    if(fileInput.eof()) {
        c=EOF;
    }
    return c;
}

int Source::getTextLine() {
    return textLine;
}

int Source::getTextPos() {
    return textPos;
}

const std::string &Source::getSource() const {
    return source;
}

void Source::setTextLine(int textLine) {
    Source::textLine = textLine;
}

void Source::setTextPos(int textPos) {
    Source::textPos = textPos;
}

int Source::getErrorTotal() const {
    return errorTotal;
}

void Source::setErrorTotal(int errorTotal) {
    Source::errorTotal = errorTotal;
}

char Source::getC() const {
    return c;
}

void Source::setC(char c) {
    Source::c = c;
}

bool Source::isOpen() {
    return input.is_open();
}
