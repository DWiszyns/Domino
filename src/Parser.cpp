//
// Created by dominik on 5/2/19.
//

#include "Parser.h"
#include <set>
#include <algorithm>
#include <iostream>

Parser::Parser(Scanner &s): scanner(s){

    SymbolType statementStartSymbols[] = {WRITEIN,WRTIEOUT,IDENTIFIER,RETURNSY};
    statementStart.insert(statementStartSymbols,statementStartSymbols+8);
    SymbolType typeSymbols[]={INTSY,CHARSY,STRINGSY,
                              FLOATSY,RATIONALSY};
    types.insert(typeSymbols, typeSymbols+5);
    SymbolType conditionalSymbols[] = {IFSY,WHILESY,FORSY};
    conditionalStatementStart.insert(conditionalSymbols,conditionalSymbols+3);

    SymbolType statementValueSymbols[] = {IDENTIFIER,INTCONST,CHARCONST,STRINGCONST,
                                          FLOATCONST,RATIONALCONST,BOOLEANSY};
    statementValue.insert(statementValueSymbols,statementValueSymbols+9);

    SymbolType multiplySymbols[] = {MULTIPLYSY,DIVIDESY};
    multiplyOperator.insert(multiplySymbols,multiplySymbols+2);
    std::set_union(statementValue.begin(),statementValue.end(),multiplyOperator.begin(),
            multiplyOperator.end(),std::inserter(factiter,std::begin(factiter)));
    SymbolType signSymbols[]={SUBTRACTSY, ADDSY};
    signs.insert(signSymbols,signSymbols+2);
    addOperator.insert(signSymbols,signSymbols+2);
    SymbolType relativeSymbols[]={EQUALS, LESSOREQUAL, LESS, MORE, MOREOREQUAL,DIFFERENT};
    relativeOperator.insert(relativeSymbols,relativeSymbols+6);
    SymbolType logicalSymbols[]={ANDSY, ORSY};
    logicalOperator.insert(logicalSymbols,logicalSymbols+6);
    nextSymbol();         // Pobranie 1-go atomu
}

void Parser::program(){
    std::cout<<"PROGRAM"<<std::endl;
    accept(FUNCSY);
    while(symbol!=MAINSY)
    {
        function();
        accept(FUNCSY);
    }
    accept(MAINSY);
    mainFunction();
    accept(EOFSY);
}

void Parser::nextSymbol(){
    symbol=scanner.nextSymbol();
}

void Parser::syntaxErrorExpected(SymbolType atom){
    scanner.scanError(atom,
                    "Expected atom: ");
}

void Parser::syntaxErrorUnexpected(SymbolType atom){
        scanner.scanError(atom,
                    "Unexpcted symbol: ");
}

void Parser::accept(SymbolType atom){
    if(symbol==atom)
    nextSymbol();
    else syntaxErrorExpected(atom);
}

void Parser::accept(const std::vector <SymbolType>& availableAtoms){
        std::set <SymbolType> availableAtomsSet (availableAtoms.begin(),availableAtoms.end());
        if(availableAtomsSet.find(symbol)!=availableAtomsSet.end())
            nextSymbol();
        else syntaxErrorExpected(symbol);
}

void Parser::function() {
    std::cout<<"function"<<std::endl;
    accept(IDENTIFIER);
    parametersDefinition();
    accept(COLON);
    if(types.find(symbol)==types.end()){
        syntaxErrorExpected(symbol);
    }
    nextSymbol();
    accept(OPENBRACKET);
    content();
    accept(CLOSEBRACKET);

}

void Parser::mainFunction() {
    std::cout<<"MAINFUNCTION"<<std::endl;
    parameters();
    accept(COLON);
    accept(VOIDSY);
    accept(OPENBRACKET);
    content();
    accept(CLOSEBRACKET);

}

void Parser::content(){
    std::cout<<"CONTENT"<<std::endl;
    while(symbol!=CLOSEBRACKET && symbol!=EOFSY)
    {
       if(conditionalStatementStart.find(symbol)!=conditionalStatementStart.end())
           conditionalStatement();
       else
       {
           statement();
           accept(SEMICOLON);
       }
    }
}


void Parser::variableDeclaration(){
    std::cout<<"VARIABLE DECLARATION"<<std::endl;
    if(types.find(symbol)==types.end())
        syntaxErrorUnexpected(symbol);
    nextSymbol();
    accept(IDENTIFIER);
    while(symbol==COMA){
        nextSymbol();
        accept(IDENTIFIER);
    }
    if(symbol==ASSIGN) //TODO co z arrayami?{
        assignment();
}


void Parser::statement(){
    std::cout<<"Statement"<<std::endl;
    switch(symbol)
    {
        case WRITEIN:
            writeInStatement();     break;
        case WRTIEOUT:
            writeOutStatement();    break;
        case IDENTIFIER : {
            nextSymbol();
            if (symbol == OROUNDBRACKET)
                parameters();
            else
                assignment();
            break;
        }
        case RETURNSY:{
            returnStatement();break;
        }
        case INTSY:case STRINGSY: case RATIONALSY:case FLOATSY: case CHARSY:{
            variableDeclaration();
            break;
        }
        default:
            syntaxErrorUnexpected(symbol);
            break;
    }
}

void Parser::ifStatement(){
    std::cout<<"IF"<<std::endl;
    accept(IFSY);
    accept(OROUNDBRACKET);
    conditionalExpression();
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    content();
    accept(CLOSEBRACKET);
    bool canUseIf=true;
    while (symbol == ELSESY){
        nextSymbol();
        if(symbol==IFSY&&canUseIf){
            accept(OROUNDBRACKET);
            conditionalExpression();
            accept(CROUNDBRACKET);
            accept(OPENBRACKET);
            content();
            accept(CLOSEBRACKET);
        }
        else if(!canUseIf&&symbol==IFSY)
            syntaxErrorUnexpected(symbol);
        else if(canUseIf&&symbol!=IFSY){
            canUseIf=false;
            accept(OPENBRACKET);
            content();
            accept(CLOSEBRACKET);
        }
    }
}

void Parser::whileStatement(){
    std::cout<<"WHILE"<<std::endl;
    accept(WHILESY);
    accept(OROUNDBRACKET);
    conditionalExpression();
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    content();
    accept(CLOSEBRACKET);
}
void Parser::assignment(){
    std::cout<<"ASSGNMENT"<<std::endl;
    accept(ASSIGN);
    expression();
}

void Parser::writeInStatement(){
    std::cout<<"writeIn"<<std::endl;
    accept(WRITEIN);
    while (symbol==INPUTSTREAM)
    {
        accept(INPUTSTREAM);
        variable();
    }
}

void Parser::writeOutStatement(){
    std::cout<<"WRITEOUT"<<std::endl;
    accept(WRTIEOUT);
    while (symbol==OUTPUTSTREAM){
        nextSymbol();
        expression();
    }
}

void Parser::factor() {
    std::cout<<"FACTOR"<<std::endl;
    if(statementValue.find(symbol)!=statementValue.end()){
      SymbolType currSymbol=symbol;
      nextSymbol();
      if(symbol==OROUNDBRACKET&&currSymbol==IDENTIFIER){
          parameters();
      }
  }
  else if(symbol==OROUNDBRACKET){
      expression();
      accept(CROUNDBRACKET);
  }


}

void Parser::simpleExpression() {
    std::cout<<"SIMPLE EXPRESSION"<<std::endl;
    factor();
    while(multiplyOperator.find(symbol)!=multiplyOperator.end()){
        nextSymbol();
        factor();
    }

}

void Parser::expression(){
    std::cout<<"EXPRESSION"<<std::endl;
    if(signs.find(symbol)!=signs.end()) nextSymbol();
    simpleExpression();
    while(addOperator.find(symbol)!=addOperator.end()){
        nextSymbol();
        simpleExpression();
    }
}

void Parser::parameters() {
    accept(OROUNDBRACKET);
    expression();
    while(symbol==COMA){
        accept(COMA);
        expression();
    }
    accept(CROUNDBRACKET);

}

void Parser::conditionalStatement() {
    switch(symbol) {
        case IFSY:
            ifStatement();
            break;
        case WHILESY:
            whileStatement();
            break;
        case FORSY:
            forStatement();
            break;
        default:
            syntaxErrorUnexpected(symbol);
            break;
    }
}

void Parser::forStatement() {
    std::cout<<"FOR"<<std::endl;
    accept(FORSY);
    accept(OROUNDBRACKET);
    statement();
    accept(SEMICOLON);
    conditionalExpression();
    accept(SEMICOLON);
    statement();
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    content();
    accept(CLOSEBRACKET);

}

void Parser::returnStatement() {
    std::cout<<"RETURN"<<std::endl;
    accept(RETURNSY);
    expression();
}

void Parser::conditionalExpression() {
    std::cout<<"CONDITIONAL EXPRESSION"<<std::endl;
    condition();
    while(logicalOperator.find(symbol)!=logicalOperator.end()){
        nextSymbol();
        condition();
    }

}

void Parser::variable() {
    std::cout<<"VARIABLE"<<std::endl;
    accept(IDENTIFIER);
    if(symbol==OTABLEBRACKET){
        nextSymbol();
        expression();
        accept(CTABLEBRACKET);
    }

}

void Parser::condition() {
    std::cout<<"CONDITION"<<std::endl;
    expression();
    if(relativeOperator.find(symbol)!=relativeOperator.end()){
        nextSymbol();
        expression();
    }
}

void Parser::parametersDefinition() {
    accept(OROUNDBRACKET);
    if(types.find(symbol)==types.end()) {
        syntaxErrorUnexpected(symbol);
    }
    nextSymbol();
    accept(IDENTIFIER);
    while(symbol==COMA){
        accept(COMA);
        if(types.find(symbol)==types.end()) {
            syntaxErrorUnexpected(symbol);
        }
        else
            nextSymbol();
        accept(IDENTIFIER);
    }
    accept(CROUNDBRACKET);

}









