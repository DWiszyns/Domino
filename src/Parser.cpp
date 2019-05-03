//
// Created by dominik on 5/2/19.
//

#include "Parser.h"
#include "Synchronize.h"
#include <set>
#include <algorithm>
#include <iostream>

Parser::Parser(Scanner &s): scanner(s){

    SymbolType statementStartSymbols[] = {WRITEIN,WRTIEOUT,IDENTIFIER,RETURNSY};
    statementStart.insert(statementStartSymbols,statementStartSymbols+8);
    SymbolType typeSymbols[]={INTSY,CHARSY,STRINGSY,
                              FLOATSY,RATIONALSY};
    types.insert(typeSymbols, typeSymbols+4);
    SymbolType conditionalSymbols[] = {IFSY,WHILESY,FORSY};
    conditionalStatementStart.insert(conditionalSymbols,conditionalSymbols+3);

    SymbolType statementValueSymbols[] = {IDENTIFIER,INTCONST,CHARCONST,STRINGCONST,
                                          FLOATCONST,RATIONALCONST,OROUNDBRACKET};
    statementValue.insert(statementValueSymbols,statementValueSymbols+8);

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
    back   = MAXSYM; // Znacznik braku atomu poprzedniego
    nextSymbol();         // Pobranie 1-go atomu
}

void Parser::program(void){
    std::cout<<"program"<<std::endl;
    accept(FUNCSY);
    while(symbol!=MAINSY)
    {
        function();
        accept(FUNCSY);
    }
    accept(MAINSY);
    mainFunction();
    accept(IDENTIFIER);
}

void Parser::function() {
    std::cout<<"function"<<std::endl;
    accept(IDENTIFIER);
    parameters();
    accept(COLON);
    if(types.find(symbol)==types.end()){
        syntaxError(symbol);
        nextSymbol();
    }
    accept(OPENBRACKET);
    std::set<SymbolType>  temp;
    temp.insert(CLOSEBRACKET);
    content(temp);

}

void Parser::mainFunction() {
    std::cout<<"mainfunction"<<std::endl;
    parameters();
    accept(COLON);
    accept(VOIDSY);
    accept(OPENBRACKET);
    std::set<SymbolType>  temp;
    temp.insert(CLOSEBRACKET);
    content(temp);

}
//wyzej spoko poza konstruktorem

void Parser::content(const std::set<SymbolType> &fs){
    std::cout<<"content"<<std::endl;
    while(symbol!=CLOSEBRACKET && symbol!=EOFSY)
    {
       if(conditionalStatementStart.find(symbol)!=conditionalStatementStart.end())
           conditionalStatement(fs);
       else
       {
            Statement(fs);
            accept(SEMICOLON);
       }
    }
    accept(CLOSEBRACKET);
}

void Parser::VarPart(const std::set<SymbolType>&  fs) // ???
{
    // x("VarPart", fs);
    //std::set_union(fs.begin(),fs.end(),addOperator.begin(),
     //              addOperator.end(),std::inserter(temp,std::begin(temp)));
    //Synchronize s(fs + varsy, fs);
    //if(!can_parse) return;
    if(symbol==CHARSY)
    {
        accept(CHARSY);
        do
        {
//            VarDeclaration(fs + SEMICOLON);
            accept(SEMICOLON);
        } while (symbol==IDENTIFIER);
    }
}

// VarDecl = ident { ',' ident } ':' Type ;
void Parser::VarDeclaration(const std::set<SymbolType>&  fs){
    // x("VarDec", fs);
    Synchronize s(std::set<SymbolType>{IDENTIFIER,
                         COMA, COLON}, fs);
    if(!can_parse) return;
    accept(IDENTIFIER);
    while(symbol==COMA)
    {
        accept(COMA);
        accept(IDENTIFIER);
    }
    accept(COLON);
    Type(fs);
}

void Parser::Type(const std::set<SymbolType>&  fs) //??
{
    // x("Type", fs);
    //Synchronize s(std::set<SymbolType>(IDENTIFIER), fs);
    if(!can_parse) return;
    if(symbol==IDENTIFIER) SimpleType(fs);
    else
// ArrayType
    {
        //accept(arraysy);
        accept(OTABLEBRACKET);
        //IndexRange(fs + std::set<SymbolType>(CTABLEBRACKET));
        accept(CTABLEBRACKET);
        //accept(ofsy);
        SimpleType(fs);
    }
}

// SimpType = TypeIdent ;
void Parser::SimpleType(const std::set<SymbolType>& fs) //??
{
    if(can_parse) accept(IDENTIFIER);
}


void Parser::Statement(const std::set<SymbolType>&  fs){
    std::cout<<"Statement"<<std::endl;
    switch(symbol)
    {
        case WRITEIN:
            writeInStatement(fs);     break;
        case WRTIEOUT:
            writeOutStatement(fs);    break;
        case IDENTIFIER ://ogarnij
            nextSymbol(); // Symbol za ident
            if(fs.find(symbol)!=fs.end())   // To nie wywolananie
                        {
                            symBack(IDENTIFIER);      // Wycofaj symbol
                            assignment(fs);
                        }
        case RETURNSY:
            returnStatement(fs);
        default:
            syntaxError1(symbol);
            break;
    }
}

void Parser::ifStatement(const std::set<SymbolType> &fs){
    std::cout<<"IF"<<std::endl;
    accept(IFSY);
    accept(OROUNDBRACKET);
    conditionalExpression(fs);
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    content(fs);
    accept(CLOSEBRACKET);
    if (symbol == ELSESY)
    {
       //to trzeba wymyslcec while()
    }
}

void Parser::whileStatement(const std::set<SymbolType> &fs){
// Synchronizacja w procedurze Statement()
    std::cout<<"WHILE"<<std::endl;
    accept(WHILESY);
    accept(OROUNDBRACKET);
    conditionalExpression(fs);
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    content(fs);
    accept(CLOSEBRACKET);
}
void Parser::assignment(const std::set<SymbolType> &fs)
{
// Synchronizacja w procedurze Statement()
    // t("Assgn", -1);
    //variable(fs + ASSIGN);
    std::cout<<"ASSGNMENT"<<std::endl;
    accept(ASSIGN);
    expression(fs);
}

void Parser::writeInStatement(const std::set<SymbolType> &fs)
{
    std::cout<<"writeIn"<<std::endl;
    accept(WRITEIN);
    while (symbol==INPUTSTREAM)
    {
        accept(INPUTSTREAM);
        variable(fs);
    }
}

void Parser::writeOutStatement(const std::set<SymbolType> &fs)
{
    std::cout<<"writeOut"<<std::endl;
    accept(WRTIEOUT);
    while (symbol==OUTPUTSTREAM)
    {
        nextSymbol();
        expression(fs);
    }
}

void Parser::expression(const std::set<SymbolType> &fs){

}

void Parser::Term(const std::set<SymbolType> &fs) {

}

// SimpExpr = Sign Term { AddOp Term } ;
void Parser::SimpleExpression(const std::set<SymbolType>&  fs)
{
    // x("SimExp", fs);
    std::set<SymbolType>  temp;

    std::set_union(statementValue.begin(),statementValue.end(),signs.begin(),
                   signs.end(),std::inserter(temp,std::begin(temp)));
    Synchronize s(temp, fs);
    if(!can_parse) return;
    if(signs.find(symbol)!=signs.end()) nextSymbol();
    std::set_union(fs.begin(),fs.end(),addOperator.begin(),
                   addOperator.end(),std::inserter(temp,std::begin(temp)));
    Term(temp);
    while(addOperator.find(symbol)!=addOperator.end())
    {
        nextSymbol();
        Term(temp);
    }
}

void Parser::parameters() {
    accept(OROUNDBRACKET);
    accept(IDENTIFIER);
    while(symbol==COMA)
    {
        accept(COMA);
        accept(IDENTIFIER);
    }
    accept(CROUNDBRACKET);

}

void Parser::conditionalStatement(const std::set<SymbolType> &fs) {
    switch(symbol) {
        case IFSY:
            ifStatement(fs);
            break;
        case WHILESY:
            whileStatement(fs);
            break;
        case FORSY:
            forStatement(fs);
            break;
        default:
            syntaxError1(symbol);
            break;
    }
}

void Parser::forStatement(const std::set<SymbolType> &fs) {
    std::cout<<"FOR"<<std::endl;
    accept(FORSY);
    accept(OROUNDBRACKET);
    Statement(fs);
    accept(SEMICOLON);
    conditionalExpression(fs);
    accept(SEMICOLON);
    Statement(fs);
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    content(fs);
    accept(CLOSEBRACKET);

}

void Parser::returnStatement(const std::set<SymbolType> &fs) {
    accept(RETURNSY);
}

// Expr = SimpExpr | SimpExpr RelOp SimpExpr ;
void Parser::conditionalExpression(const std::set<SymbolType> &fs) { //???
    std::set<SymbolType>  temp;
    std::set_union(fs.begin(),fs.end(),relativeOperator.begin(),
                   relativeOperator.end(),std::inserter(temp,std::begin(temp)));
    SimpleExpression(temp);
    if(relativeOperator.find(symbol)!=relativeOperator.end())
    {
        nextSymbol();
        SimpleExpression(fs);
    }

}

void Parser::variable(const std::set<SymbolType> &fs) {
    //Synchronize s(temp, fs); sprawdzimy czy zmienna juz zadeklarowana

}






