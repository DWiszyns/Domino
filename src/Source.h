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
    int errorTotal;
    char c;
    std::ifstream we;


public:
    Source(std::string source);
    ~Source();
    void Error(std::string word, int atomLine, int atomPos, std::string errorLabel);
    char nextChar();
    int getTextLine();
    int getTextPos();
    const std::string &getSource() const;

    void setTextLine(int textLine);

    void setTextPos(int textPos);

    int getErrorTotal() const;

    void setErrorTotal(int errorTotal);

    char getC() const;

    void setC(char c);

    bool isOpen();


};


#endif //DOMINO_SOURCE_H
