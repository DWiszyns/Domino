//
// Created by dominik on 5/2/19.
//

#include "Parser.h"
#include "ast/Program.h"
#include <set>
#include <algorithm>
#include <iostream>
#include "ast/Variable.h"

Parser::Parser(Scanner &s): scanner(s){
    statementStart={WRITEIN,WRITEOUT,IDENTIFIER,RETURNSY};
    types={INTSY,CHARSY,STRINGSY,FLOATSY,RATIONALSY,VOIDSY};
    conditionalStatementStart={IFSY,WHILESY,FORSY};
    statementValue={IDENTIFIER,INTCONST,CHARCONST,STRINGCONST,
                    FLOATCONST,RATIONALCONST,BOOLEANSY};
    multiplyOperator={MULTIPLYSY,DIVIDESY};
    endOfStream={EOFSY,ENDOFTEXT};
    signs={SUBTRACTSY, ADDSY};
    relativeOperator={EQUALS, LESSOREQUAL, LESS, MORE, MOREOREQUAL,DIFFERENT};
    logicalOperator={ANDSY, ORSY};
    nextSymbol();
}

std::unique_ptr<Program> Parser::parse(){
    std::cout<<"PROGRAM"<<std::endl;
    accept(FUNCSY);
    while(symbol!=MAINSY)
    {
        function();
        accept(FUNCSY);
    }
    accept(MAINSY);
    MainFunction myMain(mainFunction());
    accept(endOfStream);
    Program a(2,3);
    return std::make_unique<Program>(myMain);
}

void Parser::nextSymbol(){
    token= scanner.nextToken();
    symbol=token.getType();
}

void Parser::syntaxErrorExpected(SymbolType atom){
    scanner.scanError(atom,
                    "Error expected token: ");
    skipTo(atom);
}

void Parser::syntaxErrorUnexpected(SymbolType atom){
    scanner.scanError(atom,
                    "Error unexpcted symbol: ");
    nextSymbol();    
}

void Parser::syntaxErrorUnexpected(SymbolType atom, std::set <SymbolType> expectedAtoms){
    scanner.scanError(atom,
                    "Error unexpcted symbol: ");
    skipTo(expectedAtoms);
}

void Parser::accept(SymbolType atom){
    if(symbol==atom)
        nextSymbol();
    else syntaxErrorExpected(atom);
}

void Parser::accept(const std::set <SymbolType>& availableAtoms){
        std::set <SymbolType> availableAtomsSet (availableAtoms.begin(),availableAtoms.end());
        if(availableAtoms.find(symbol)!=availableAtoms.end())
            nextSymbol();
        else syntaxErrorExpected(symbol);
}

void Parser::function() {
    std::cout<<"FUNCTION"<<std::endl;
    accept(IDENTIFIER);
    std::string funcName=token.getValue();
    ParametersDefinition parameters(parametersDefinition());
    accept(COLON);
    if(types.find(symbol)==types.end()){
        syntaxErrorUnexpected(symbol);
    }
    SymbolType type=token.getType();
    nextSymbol();
    accept(OPENBRACKET);
    //Content content=
    content();
    accept(CLOSEBRACKET);
 //   scope.addFunction(Function(funcName,type,parameters,content))

}

MainFunction Parser::mainFunction() {
    std::cout<<"MAINFUNCTION"<<std::endl;
    parametersDefinition();
    accept(COLON);
    accept(VOIDSY);
    accept(OPENBRACKET);
    Content myContent(content());
    accept(CLOSEBRACKET);
    return MainFunction(myContent);

}

Content Parser::content(){
    std::cout<<"CONTENT"<<std::endl;
    std::list<std::unique_ptr<Statement>> statements;
    while(symbol!=CLOSEBRACKET && (endOfStream.find(symbol)==endOfStream.end()))
    {
       if(conditionalStatementStart.find(symbol)!=conditionalStatementStart.end())
           conditionalStatement();
       else
       {
           statements.push_back(std::move(statement()));
           accept(SEMICOLON);
       }
    }
    return Content(std::move(statements),&scope);
}


VariableDeclaration& Parser::variableDeclaration(){
    //trzeba dodac zmienna do Scope'a
    std::cout<<"VARIABLE DECLARATION"<<std::endl;
    if(types.find(symbol)==types.end())
        syntaxErrorUnexpected(symbol,types);
    TypeKind type = getTypeFromSymbol(symbol);
    nextSymbol();
    std::string name=token.getValue();
    accept(IDENTIFIER);
    int size=1;
    if(symbol==OTABLEBRACKET) {
        size = arrayDeclaration();
        VariableDeclaration varDec(scope, type, name, static_cast<unsigned int>(size));
        return varDec;
    }
    else{
        std::vector<Variable> variables;
        /*
        while(symbol==COMA){
            nextSymbol();
            accept(IDENTIFIER);
        }
         */
        if(symbol==ASSIGN) {
            VariableDeclaration varDec(scope, type, name, assignment(Variable(name, size, type), 0));
            return varDec;
        }
    }

}

int Parser::arrayDeclaration() {
    std::cout<<"ARRAY DECLARATION"<<std::endl;
    accept(OTABLEBRACKET);
    //expression();originally I think we need value
    int size = std::stoi(token.getValue());
    accept(INTCONST);
    accept(CTABLEBRACKET);
}


std::unique_ptr<Statement> Parser::statement(){
    std::cout<<"STATEMENT"<<std::endl;
    std::unique_ptr<Statement> statement;
    switch(symbol)
    {
        case WRITEIN:
            writeInStatement();     break;
        case WRITEOUT:
            writeOutStatement();    break;
        case IDENTIFIER : {
            std::string name=token.getValue();
            nextSymbol();
            if (symbol == OROUNDBRACKET)
            {
                parameters();
                accept(CROUNDBRACKET);
                //funccall
            }
            else {
                Variable myVariable(scope.getVariable(name));
                int index=0;
                if(symbol==OTABLEBRACKET)
                {
                    nextSymbol();
                    if(symbol==INTCONST) index=std::stoi(token.getValue());
                    //std::unique_ptr<Expression> express=expression();
                    accept(CTABLEBRACKET);
                }
                if (myVariable.getName() == "emptyvariable")
                    throw "Variable not declared";
                statement=std::make_unique<Assignment>(
                        assignment(myVariable,static_cast<unsigned int>(index)));
                break;
            }
        }
        case RETURNSY:{
            returnStatement();break;
        }
        case INTSY:case STRINGSY: case RATIONALSY:case FLOATSY: case CHARSY:{
            statement =std::make_unique<VariableDeclaration>(variableDeclaration());
            break;
        }
        default:
            syntaxErrorUnexpected(symbol);
            break;
    }
    return statement;

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
Assignment Parser::assignment(Variable variable,unsigned int i){
    std::cout<<"ASSGNMENT"<<std::endl;
    accept(ASSIGN);
    return Assignment(&variable,expression(),i);
}


void Parser::writeInStatement(){
    std::cout<<"WRITEIN"<<std::endl;
    accept(WRITEIN);
    while (symbol==INPUTSTREAM)
    {
        accept(INPUTSTREAM);
        variable();
    }
}

void Parser::writeOutStatement(){
    std::cout<<"WRITEOUT"<<std::endl;
    accept(WRITEOUT);
    while (symbol==OUTPUTSTREAM){
        nextSymbol();
        expression();
    }
}

std::unique_ptr<Factor> Parser::factor() {
    std::cout<<"FACTOR"<<std::endl;
    if(statementValue.find(symbol)!=statementValue.end()){
      SymbolType currSymbol=symbol;
      std::string name=token.getValue();
      nextSymbol();
      if(currSymbol==IDENTIFIER){
          Variable x(scope.getVariable(name));
          if(x.getName()=="emptyvariable")
              throw  "Variable not declared";
          return std::make_unique<ValueFactor>(x.getNode());
      }
      /* funccall
      if(symbol==OROUNDBRACKET&&currSymbol==IDENTIFIER){
          parameters();
      }
       */
      return std::make_unique<ValueFactor>(name);
      //TODO czy zmienna zadeklarowana? jaki typ zmiennej?
  }else if(symbol==OROUNDBRACKET){
      std::unique_ptr<Factor> factorPointer=std::make_unique<ExpressionFactor>(expression());
      accept(CROUNDBRACKET);
      return factorPointer;

    }
}

std::unique_ptr<SimpleExpression> Parser::simpleExpression() {
    std::list <std::unique_ptr<Factor>> factors;
    std::list <SymbolType > multiplyOperators;
    std::cout<<"SIMPLE EXPRESSION"<<std::endl;
    factors.push_back(std::move(factor()));
    while(multiplyOperator.find(symbol)!=multiplyOperator.end()){
        multiplyOperators.push_back(symbol);
        nextSymbol();
        factors.push_back(std::move(factor()));
    }
    return std::make_unique<SimpleExpression>(std::move(factors),multiplyOperators);
}

std::unique_ptr<Expression> Parser::expression(){
    std::list <std::unique_ptr<SimpleExpression>> simpleExpressions;
    std::list <SymbolType > addOperators;
    std::cout<<"EXPRESSION"<<std::endl;
    if(signs.find(symbol)!=signs.end()) nextSymbol();
    simpleExpressions.push_back(simpleExpression());
    while(signs.find(symbol)!=signs.end()){
        addOperators.push_back(symbol);
        nextSymbol();
        simpleExpressions.push_back(simpleExpression());
    }
    return std::make_unique<Expression>(std::move(simpleExpressions),addOperators);
}

void Parser::parameters() {
    accept(OROUNDBRACKET);
    expression();
    while(symbol==COMA){
        accept(COMA);
        expression();
    }
    accept(CROUNDBRACKET);
    //return std::vector<Variable> parameters;
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

std::unique_ptr<Variable> Parser::variable() {//do I need you?//maybe let's have node returning it
    std::string name=token.getValue();
    Variable x(scope.getVariable(token.getValue()));
    if(x.getName()=="emptyvariable")
        throw  "Variable not declared";
    std::cout<<"VARIABLE"<<std::endl;
    accept(IDENTIFIER);
    if(symbol==OTABLEBRACKET){
        nextSymbol();
        std::unique_ptr<Expression> someExpression(std::move(expression()));
        std::vector<std::unique_ptr<Node>> nodes;
        nodes.push_back(std::make_unique<Node>(x.getNodeByIndex(someExpression->execute().getValue().integer)));
        accept(CTABLEBRACKET);
        return std::make_unique<Variable>("copy",std::move(nodes),1);//chyba zle
    }
    return std::make_unique<Variable>(x);

}

void Parser::condition() {
    std::cout<<"CONDITION"<<std::endl;
    expression();
    if(relativeOperator.find(symbol)!=relativeOperator.end()){
        nextSymbol();
        expression();
    }
}

ParametersDefinition Parser::parametersDefinition() {
    accept(OROUNDBRACKET);
    std::vector<Variable> parameters;
    if(symbol!=CROUNDBRACKET) {
        if (types.find(symbol) == types.end()) {
            syntaxErrorUnexpected(symbol, types);
        }
        TypeKind type=getTypeFromSymbol(token.getType());
        nextSymbol();
        std::string name=token.getValue();
        accept(IDENTIFIER);
        Variable x(name,1,type);
        parameters.push_back(x);// i don't think we need to initialize our vector
        while (symbol == COMA) {
            accept(COMA);
            if (types.find(symbol) == types.end()) {
                syntaxErrorUnexpected(symbol, types);
            } else {
                type = getTypeFromSymbol(token.getType());
                nextSymbol();
            }
            accept(IDENTIFIER);
            name=token.getValue();
            parameters.emplace_back(name,1,type);// i don't think we need to initialize our vector
        }
    }
    accept(CROUNDBRACKET);
    return ParametersDefinition(parameters);
}

void Parser::skipTo(SymbolType atom){
    while(symbol!=atom&&symbol!=EOFSY) 
        nextSymbol();
    nextSymbol();    
}

void Parser::skipTo(std::set<SymbolType> atoms){
    while(atoms.find(symbol)==atoms.end()&&symbol!=EOFSY) 
        nextSymbol();
    nextSymbol();
}

TypeKind Parser::getTypeFromSymbol(SymbolType symbol) {
    switch(symbol){
        case INTSY:return INT;
        case FLOATSY:return FLOAT;
        case STRINGSY:return STRING;
        case CHARSY:return CHAR;
        case BOOLEANSY:return BOOLEAN;
        case RATIONALSY:return RATIONAL;
        default:return INT;
    }
}
