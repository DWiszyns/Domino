//
// Created by dominik on 5/2/19.
//

#ifndef DOMINO_PARSER_H
#define DOMINO_PARSER_H


#include "Scanner.h"
#include "Token.h"
#include "ast/Program.h"
#include <set>
#include <vector>
#include <memory>

//std::set<SymbolType> to zbior symboli pozwalajacych na konkretna operacje


class Parser {
    Scanner&    scanner;
    SymbolType  symbol;
    Token token = Token(OTHERS,"");
    std::set<SymbolType> statementStart,   conditionalStatementStart;
    std::set<SymbolType> statementValue, endOfStream, multiplyOperator;
    std::set<SymbolType> addOperator,    signs,    relativeOperator;
    std::set<SymbolType> types,logicalOperator;

    void nextSymbol();
    virtual void syntaxErrorExpected(SymbolType atom);
    void syntaxErrorUnexpected(SymbolType atom);
    void syntaxErrorUnexpected(SymbolType atom,std::set <SymbolType> expectedAtoms);
    void skipTo(SymbolType atom);
    void skipTo(std::set<SymbolType> expectedAtoms);
    void accept(SymbolType atom);
    void accept(const std::set <SymbolType>& availableAtoms);
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
    void arrayDeclaration();
public:
    Parser(Scanner&);
    std::unique_ptr<Program> parse();
};


#endif //DOMINO_PARSER_H
