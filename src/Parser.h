//
// Created by dominik on 5/2/19.
//

#ifndef DOMINO_PARSER_H
#define DOMINO_PARSER_H


#include "Scanner.h"
#include <set>

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
    void syntaxError(int atom)
// Oczekiwany atom
    {
        scanner.scanError(FirstSyntaxError+atom,
                    "Unexpected atom: "/*, AT[atom]*/);
    }
    void syntaxError1(int atom)
// Nieoczekiwany atom
    {
        scanner.scanError(FirstSyntaxError+atom,
                    "Unexpcted symbol: "/*, AT[atom]*/);
    }
    void accept(SymbolType atom)
    {
        if(symbol==atom)
            nextSymbol();
        else syntaxError(atom);
    };
// PROCEDURY ROZBIORU (prywatne)
    void content(const std::set<SymbolType> &fs);
    void VarPart          (const std::set<SymbolType>& fs);
    void VarDeclaration   (const std::set<SymbolType>& fs);
    void Type             (const std::set<SymbolType>& fs);
    void SimpleType       (const std::set<SymbolType>& fs);
    void ProcPart         (const std::set<SymbolType>& fs);
    void StatementPart    (const std::set<SymbolType>& fs);
    void Statement        (const std::set<SymbolType>& fs);
    void CompoundStatement(const std::set<SymbolType>& fs);
    void ifStatement(const std::set<SymbolType> &fs);
    void whileStatement(const std::set<SymbolType> &fs);
// PROCEDURY ROZBIORU,  cd
    void assignment(const std::set<SymbolType> &fs);
    void writeInStatement(const std::set<SymbolType> &fs);
    void InputVariable    (const std::set<SymbolType>& fs);
    void writeOutStatement(const std::set<SymbolType> &fs);
    void OutputValue      (const std::set<SymbolType>& fs);
    void expression(const std::set<SymbolType> &fs);
    void SimpleExpression (const std::set<SymbolType>& fs);
    void Term             (const std::set<SymbolType>& fs);
    void Factor           (const std::set<SymbolType>& fs);
    void variable(const std::set<SymbolType> &fs);
    void function           ();
    void mainFunction       ();
    void parameters         ();
    void conditionalStatement (const std::set<SymbolType>& fs);
    void forStatement       (const std::set<SymbolType>& fs);
    void returnStatement    (const std::set<SymbolType>& fs);
    void conditionalExpression (const std::set<SymbolType>& fs);
public:
    Parser(Scanner&);
    void program(void);   // Glówna procedura rozbioru

    int logicalOperator;
};


#endif //DOMINO_PARSER_H
