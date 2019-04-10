//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SOURCE_H
#define DOMINO_SOURCE_H


#include <string>
#include <fstream>


class Source {
    const std::string source;
    int textLine;
    int textPos;
    int inWordPos;
    int errorTotal;
    std::string word;
    std::ifstream we; //otwarcie pliku wejsciowego


public:
    Source(std::string source);
    ~Source();
    void Error(std::string word, int atomLine, int atomPos, std::string errorLabel);
    char nextChar();
    int nextString();
    int getTextLine();
    int getTextPos();


};


#endif //DOMINO_SOURCE_H
