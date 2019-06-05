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
#include <algorithm>
#include <iostream>
#include "ast/Node/Variable.h"
#include "ast/Statements/WriteOutStatement.h"
#include "ast/Statements/IfStatement.h"
#include "ast/Statements/WhileStatement.h"

//std::set<SymbolType> to zbior symboli pozwalajacych na konkretna operacje


class Parser {
    Scanner&    scanner;
    SymbolType  symbol;
    Scope *scope;
    Token token = Token(OTHERS,"");
    std::set<SymbolType> statementStart,   conditionalStatementStart;
    std::set<SymbolType> statementValue, endOfStream, multiplyOperator;
    std::set<SymbolType> addOperator,    signs,    relativeOperator;
    std::set<SymbolType> types,logicalOperator;
    std::list<Scope*> toDelete;
    void nextSymbol();
    virtual void syntaxErrorExpected(SymbolType atom);
    void syntaxErrorUnexpected(SymbolType atom);
    void syntaxErrorUnexpected(SymbolType atom,std::set <SymbolType> expectedAtoms);
    void skipTo(SymbolType atom);
    void skipTo(std::set<SymbolType> expectedAtoms);
    void accept(SymbolType atom);
    void accept(const std::set <SymbolType>& availableAtoms);
    Content content();
    std::unique_ptr<VariableDeclaration> variableDeclaration();
    std::unique_ptr<Statement> statement();
    std::unique_ptr<IfStatement> ifStatement();
    std::unique_ptr<WhileStatement> whileStatement();
    std::unique_ptr<Assignment>  assignment(Variable* variable,unsigned int i);
    void writeInStatement();
    std::unique_ptr<WriteOutStatement> writeOutStatement();
    std::unique_ptr<Expression> expression();
    std::unique_ptr<SimpleExpression> simpleExpression();
    std::unique_ptr<Factor> factor();
    std::unique_ptr<Variable> variable();
    Function function();
    MainFunction mainFunction       ();
    void parameters         ();
    std::unique_ptr<Statement> conditionalStatement ();
    void forStatement       ();
    void returnStatement    ();
    std::unique_ptr<ConditionalExpression> conditionalExpression ();
    std::unique_ptr<Condition> condition              ();
    ParametersDefinition parametersDefinition();
    int arrayDeclaration();
    static TypeKind getTypeFromSymbol(SymbolType symbol);
public:
    Parser(Scanner&);
    ~Parser();
    std::unique_ptr<Program> parse();
};


#endif //DOMINO_PARSER_H
