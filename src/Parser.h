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
    friend class Synchronize;
// Klasa do detekcji b
    enum{ FirstSyntaxError=10 };
    Scanner&    scanner;
// Modu scanera
    SymbolType  symbol;
// Ostatnio pobrany atom z scanner
    SymbolType  back;
// Symbol wycofany przez parser
    bool     can_parse;
// 1 jeli synchronizacja OK
// Podzbiory atomów
    std::set<SymbolType> statementStart,   conditionalStatementStart,    stiter;
    std::set<SymbolType> statementValue, factiter, multiplyOperator;
    std::set<SymbolType> addOperator,    signs,    relativeOperator;
    std::set<SymbolType> types,logicalOperator;

    // cdTK  - Mini Pascal (parser) 6 Parser (cd1)
    void nextSymbol()
// Pobranie nastpnego symbolu
    {
        if(back==MAXSYM)
            symbol=scanner.nextSymbol();
        else
            symbol=back, back=MAXSYM;
    }
    void symBack(SymbolType atom)
    {
        back   = symbol;
        symbol = atom;
    }
    void syntaxErrorExpected(int atom)
// Oczekiwany atom
    {
        scanner.scanError(atom,
                    "Expected atom: "/*, AT[atom]*/);
    }
    void syntaxErrorUnexpected(int atom)
// Nieoczekiwany atom
    {
        scanner.scanError(atom,
                    "Unexpcted symbol: "/*, AT[atom]*/);
    }
    void accept(SymbolType atom)
    {
        if(symbol==atom)
            nextSymbol();
        else syntaxErrorExpected(atom);
    };
    void accept(const std::vector <SymbolType>& availableAtoms)
    {
        std::set <SymbolType> availableAtomsSet (availableAtoms.begin(),availableAtoms.end());
        if(availableAtomsSet.find(symbol)!=availableAtomsSet.end())
            nextSymbol();
        else syntaxErrorExpected(symbol);
    };
// PROCEDURY ROZBIORU (prywatne)
    void content();
    void variableDeclaration();
    void statement();
    void ifStatement();
    void whileStatement();
// PROCEDURY ROZBIORU,  cd
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
    void program();   // Glówna procedura rozbioru

};


#endif //DOMINO_PARSER_H
