//
// Created by dominik on 5/2/19.
//

#ifndef DOMINO_PARSER_H
#define DOMINO_PARSER_H


#include "Scanner.h"
#include <set>

//std::set<SymbolType> to zbior symboli pozwalajacych na konkretna operacje

char *AT[MAXSYM + 1] =    // Atomy tekstowo
        {
                "beg", "rd", "wrt", "if", "whl",
                "end", "thn", "els", "do", "var",
                "not", "and", "div", "or", "arr",
                "of", "prg", "prc",
                "id", "ico", "cco", "*", "+", "-",
                "<", "<=", ">", ">=", "<>", "=",
                "(", ")", "[", "]", ";", ":",
                ":=", "..", ".", ",", "???"
        };

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
    std::set<SymbolType> statementStart,   stseq,    stiter;
    std::set<SymbolType> statementSomething, factiter, multiplyOperator;
    std::set<SymbolType> addOperator,    signs,    logicalOperator;
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
                    "Spodziewany atom: ", AT[atom]);
    }
    void syntaxError1(int atom)
// Nieoczekiwany atom
    { scanner.scanError(FirstSyntaxError+atom,
                    "Nieoczekiwany symbol: ", AT[atom]);
    }
    void accept(SymbolType atom)
    {
        if(symbol==atom)
            nextSymbol();
        else syntaxError(atom);
    };
// PROCEDURY ROZBIORU (prywatne)
    void Block            (const std::set<SymbolType>& fs);
    void VarPart          (const std::set<SymbolType>& fs);
    void VarDeclaration   (const std::set<SymbolType>& fs);
    void Type             (const std::set<SymbolType>& fs);
    void SimpleType       (const std::set<SymbolType>& fs);
    void IndexRange       (const std::set<SymbolType>& fs);
    void ProcPart         (const std::set<SymbolType>& fs);
    void functionDeclaration(const std::set<SymbolType> &fs);
    void StatementPart    (const std::set<SymbolType>& fs);
    void Statement        (const std::set<SymbolType>& fs);
    void CompoundStatement(const std::set<SymbolType>& fs);
    void IfStatement      (const std::set<SymbolType>& fs);
    void WhileStatement   (const std::set<SymbolType>& fs);
// PROCEDURY ROZBIORU,  cd
    void Assignment       (const std::set<SymbolType>& fs);
    void ReadStatement    (const std::set<SymbolType>& fs);
    void InputVariable    (const std::set<SymbolType>& fs);
    void WriteStatement   (const std::set<SymbolType>& fs);
    void OutputValue      (const std::set<SymbolType>& fs);
    void Expression       (const std::set<SymbolType>& fs);
    void SimpleExpression (const std::set<SymbolType>& fs);
    void Term             (const std::set<SymbolType>& fs);
    void Factor           (const std::set<SymbolType>& fs);
    void Variable         (const std::set<SymbolType>& fs);
public:
    Parser(Scanner&);
    void Program(void);   // Glówna procedura rozbioru

};


#endif //DOMINO_PARSER_H
