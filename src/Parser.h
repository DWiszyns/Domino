//
// Created by dominik on 5/2/19.
//

#ifndef DOMINO_PARSER_H
#define DOMINO_PARSER_H


#include "Scanner.h"
#include <set>
#include <vector>

//std::set<SymbolType> to zbior symboli pozwalajacych na konkretna operacje

/*char *AT[MAXSYM + 1] =    // Atomy tekstowo
        {
                "beg", "rd", "wrt", "if", "whl",
                "end", "thn", "els", "do", "var",
                "not", "and", "div", "or", "arr",
                "of", "prg", "prc",
                "id", "ico", "cco", "*", "+", "-",
                "<", "<=", ">", ">=", "<>", "=",
                "(", ")", "[", "]", ";", ":",
                ":=", "..", ".", ",", "???"
        };*/

class Parser {
    Scanner&    scanner;
    SymbolType  symbol;
    std::set<SymbolType> statementStart,   conditionalStatementStart,    stiter;
    std::set<SymbolType> statementValue, factiter, multiplyOperator;
    std::set<SymbolType> addOperator,    signs,    relativeOperator;
    std::set<SymbolType> types,logicalOperator;

    void nextSymbol();
    void syntaxErrorExpected(SymbolType atom);
    void syntaxErrorUnexpected(SymbolType atom);
    void syntaxErrorUnexpected(SymbolType atom,std::set <SymbolType> expectedAtoms);
    void skipto(SymbolType atom);
    void skipto(std::set <SymbolType> expectedAtoms);
    void accept(SymbolType atom);
    void accept(const std::vector <SymbolType>& availableAtoms);
    void content();
    void variableDeclaration();
    void statement();
    void ifStatement();
    void whileStatement();
    void assignment();
    void writeInStatement();
    void writeOutStatement();
    void expression();
    void simpleExpression();
    void factor();
    void variable();
    void function           ();
    void mainFunction       ();
    void parameters         ();
    void conditionalStatement ();
    void forStatement       ();
    void returnStatement    ();
    void conditionalExpression ();
    void condition              ();
    void parametersDefinition();
public:
    Parser(Scanner&);
    void program();   
};


#endif //DOMINO_PARSER_H
