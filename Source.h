//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SOURCE_H
#define DOMINO_SOURCE_H


#include <string>
#include <fstream>


class Source {
    const std::string source;
    int tLine;
    int tPos;
    int errorInLine;
    int errorTotal;
    std::ifstream we; //otwarcie pliku wejsciowego


public:
    Source(std::string source);
    ~Source();
    void Error();
    int nextChar();
    int nextString();


};


#endif //DOMINO_SOURCE_H
