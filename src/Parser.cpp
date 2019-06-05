//
// Created by dominik on 5/2/19.
//

#include "Parser.h"
#include "ast/Program.h"
#include <set>
#include <algorithm>
#include <iostream>
#include "ast/Node/Variable.h"

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
    scope =  new Scope();
}

std::unique_ptr<Program> Parser::parse(){
    accept(FUNCSY);
    while(symbol!=MAINSY)
    {
        function();
        //scope->addFunction(function());
        accept(FUNCSY);
    }
    accept(MAINSY);
    MainFunction myMain(mainFunction());
    accept(endOfStream);
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

Function Parser::function() {
    accept(IDENTIFIER);
    std::string funcName=token.getValue();
    ParametersDefinition parameters(parametersDefinition());
    accept(COLON);
    if(types.find(symbol)==types.end()){
        syntaxErrorUnexpected(symbol);
    }
    TypeKind type = getTypeFromSymbol(symbol);
    nextSymbol();
    accept(OPENBRACKET);
    Content functionContent(content());
    accept(CLOSEBRACKET);
 //   scope.addFunction(Function(funcName,type,parameters,content))
    return Function(funcName,type,parameters,functionContent);
}

MainFunction Parser::mainFunction() {
    parametersDefinition();
    accept(COLON);
    accept(VOIDSY);
    accept(OPENBRACKET);
    Content myContent(content());
    accept(CLOSEBRACKET);
    return MainFunction(myContent);

}

Content Parser::content(){
    std::list<std::unique_ptr<Statement>> statements;
    while(symbol!=CLOSEBRACKET && (endOfStream.find(symbol)==endOfStream.end()))
    {
       if(conditionalStatementStart.find(symbol)!=conditionalStatementStart.end())
           statements.push_back(std::move(conditionalStatement()));
       else
       {
           statements.push_back(std::move(statement()));
           accept(SEMICOLON);
       }
    }
    return Content(std::move(statements),scope);
}


std::unique_ptr<VariableDeclaration> Parser::variableDeclaration(){
    if(types.find(symbol)==types.end())
        syntaxErrorUnexpected(symbol,types);
    TypeKind type = getTypeFromSymbol(symbol);
    nextSymbol();
    std::string name=token.getValue();
    accept(IDENTIFIER);
    int size=1;
    if(symbol==OTABLEBRACKET) {
        size = arrayDeclaration();
        std::unique_ptr<VariableDeclaration> varDec=std::make_unique<VariableDeclaration>(scope, type, name, static_cast<unsigned int>(size));
        return varDec;
    }
    else{
        if(symbol==ASSIGN) {
            std::unique_ptr<Variable> tempVariable = std::make_unique<Variable>(name, size, type);
            std::unique_ptr<VariableDeclaration> varDec=std::make_unique<VariableDeclaration>(scope, std::move(tempVariable), assignment(tempVariable.get(), 0));
            return varDec;
        }
    }

}

int Parser::arrayDeclaration() {
    accept(OTABLEBRACKET);
    int size = std::stoi(token.getValue());
    accept(INTCONST);
    accept(CTABLEBRACKET);
    return size;
}


std::unique_ptr<Statement> Parser::statement(){
    std::unique_ptr<Statement> statement;
    switch(symbol)
    {
        case WRITEIN:
            writeInStatement();     break;
        case WRITEOUT:
            statement=std::move(writeOutStatement()); break;
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
                Variable *myVariable(scope->getVariable(name));
                int index=0;
                if(symbol==OTABLEBRACKET)
                {
                    nextSymbol();
                    if(symbol==INTCONST) index=std::stoi(token.getValue());
                    //std::unique_ptr<Expression> express=expression();
                    accept(CTABLEBRACKET);
                }
                if (myVariable->getName() == "emptyvariable")
                    throw "Variable not declared";
                statement=std::move(
                        assignment(myVariable,static_cast<unsigned int>(index)));
                break;
            }
        }
        case RETURNSY:{
            returnStatement();break;
        }
        case INTSY:case STRINGSY: case RATIONALSY:case FLOATSY: case CHARSY:{
            statement =std::move(variableDeclaration());
            break;
        }
        default:
            syntaxErrorUnexpected(symbol);
            break;
    }
    return statement;

}

std::unique_ptr<IfStatement> Parser::ifStatement(){
    accept(IFSY);
    accept(OROUNDBRACKET);
    std::vector<std::unique_ptr<ConditionalExpression>> conditions;
    std::list<Content> contents;
    conditions.push_back(std::move(conditionalExpression()));
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    auto * newScope=new Scope(scope);
    scope=newScope;
    contents.push_back(content());
    accept(CLOSEBRACKET);
    bool canUseIf=true;
    scope=scope->getExternalScope();
    toDelete.push_back(newScope);
    while (symbol == ELSESY){
        nextSymbol();
        if(symbol==IFSY&&canUseIf){
            accept(OROUNDBRACKET);
            conditions.push_back(std::move(conditionalExpression()));
            accept(CROUNDBRACKET);
            accept(OPENBRACKET);
            auto * newScope2=new Scope(scope);
            scope=newScope2;
            contents.push_back(content());
            scope=scope->getExternalScope();
            toDelete.push_back(newScope2);
            accept(CLOSEBRACKET);
        }
        else if(!canUseIf&&symbol==IFSY)
            syntaxErrorUnexpected(symbol);
        else if(canUseIf&&symbol!=IFSY){
            canUseIf=false;
            accept(OPENBRACKET);
            auto * newScope3=new Scope(scope);
            scope=newScope3;
            contents.push_back(content());
            scope=scope->getExternalScope();
            toDelete.push_back(newScope3);
            accept(CLOSEBRACKET);
        }
    }
    return std::make_unique<IfStatement>(std::move(conditions),contents);
}

std::unique_ptr<WhileStatement> Parser::whileStatement(){
    accept(WHILESY);
    accept(OROUNDBRACKET);
    std::unique_ptr<ConditionalExpression> conditional=std::move(conditionalExpression());
    accept(CROUNDBRACKET);
    accept(OPENBRACKET);
    Scope* newScope= new Scope(scope);
    scope=newScope;
    Content myContent(content());
    scope=newScope->getExternalScope();
    toDelete.push_back(newScope);
    accept(CLOSEBRACKET);
    return std::make_unique<WhileStatement>(std::move(conditional),myContent);
}

std::unique_ptr<Assignment> Parser::assignment(Variable* variable,unsigned int i){
    accept(ASSIGN);
    return std::make_unique<Assignment>(variable,expression(),i);
}


void Parser::writeInStatement(){
    accept(WRITEIN);
    while (symbol==INPUTSTREAM)
    {
        accept(INPUTSTREAM);
        variable();
    }
}

std::unique_ptr<WriteOutStatement> Parser::writeOutStatement(){
    accept(WRITEOUT);
    std::list<std::unique_ptr<Expression>> expressions;
    while (symbol==OUTPUTSTREAM){
        nextSymbol();
        expressions.push_back(std::move(expression()));
    }
    std::unique_ptr<WriteOutStatement> writeout=std::make_unique<WriteOutStatement>(scope,std::move(expressions));
    return writeout;
}

std::unique_ptr<Factor> Parser::factor() {
    bool minus=false;
    if(symbol==SUBTRACTSY){
        minus=true;
        nextSymbol();
    }
    if(statementValue.find(symbol)!=statementValue.end()){
      SymbolType currSymbol=symbol;
      std::string name=token.getValue();
      nextSymbol();
      if(currSymbol==IDENTIFIER){
          Variable *x(scope->getVariable(name));
          if(x->getName()=="emptyvariable")
              throw  "Variable not declared";
          return std::make_unique<ValueFactor>(std::move(x->getNodeReference()));
      }
      /* funccall
      if(symbol==OROUNDBRACKET&&currSymbol==IDENTIFIER){
          parameters();
      }
       */
      switch(currSymbol){
          case INTCONST:{
              int x=std::stoi(name);
              if(minus) return std::make_unique<ValueFactor>(std::make_shared<Node>(-x));
              else  return std::make_unique<ValueFactor>(std::make_shared<Node>(x));
          }
          case FLOATCONST: {
              float x = std::stof(name);
              if(minus) return std::make_unique<ValueFactor>(std::make_shared<Node>(-x));
              else  return std::make_unique<ValueFactor>(std::make_shared<Node>(x));
          }
          case RATIONALCONST:{
              if(minus) return std::make_unique<ValueFactor>(std::make_shared<Node>(Rational('-'+name)));
              else return std::make_unique<ValueFactor>(std::make_shared<Node>(Rational(name)));
          }
          default:
              return std::make_unique<ValueFactor>(std::make_shared<Node>(name));
      }
    }else if(symbol==OROUNDBRACKET){
      std::unique_ptr<Factor> factorPointer=std::make_unique<ExpressionFactor>(expression());
      accept(CROUNDBRACKET);
      return factorPointer;
    }
}

std::unique_ptr<SimpleExpression> Parser::simpleExpression() {
    std::list <std::unique_ptr<Factor>> factors;
    std::list <SymbolType > multiplyOperators;
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

std::unique_ptr<Statement> Parser::conditionalStatement() { //tu moze byc blad, bo za duzo castowania bedzie
    switch(symbol) {
        case IFSY:
            return std::move(ifStatement());
        case WHILESY:
            return std::move(whileStatement());
        case FORSY:
            forStatement();
            break;
        default:
            syntaxErrorUnexpected(symbol);
            break;
    }
}

void Parser::forStatement() {
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
    accept(RETURNSY);
    expression();
}

std::unique_ptr<ConditionalExpression> Parser::conditionalExpression() {
    std::list<std::unique_ptr<Condition>> conditions;
    std::list<SymbolType> logicalOperators;
    conditions.push_back(std::move(condition()));
    while(logicalOperator.find(symbol)!=logicalOperator.end()){
        logicalOperators.push_back(token.getType());
        nextSymbol();
        conditions.push_back(std::move(condition()));
    }
    return std::make_unique<ConditionalExpression>(std::move(conditions),logicalOperators);

}

std::unique_ptr<Variable> Parser::variable() {//do I need you?//maybe let's have node returning it
    std::string name=token.getValue();
    Variable* x(scope->getVariable(token.getValue()));
    if(x->getName()=="emptyvariable")
        throw  "Variable not declared";
    accept(IDENTIFIER);
    if(symbol==OTABLEBRACKET){
        nextSymbol();
        std::unique_ptr<Expression> someExpression(std::move(expression()));
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_unique<Node>(x->getNodeByIndex(someExpression->execute().getValue().integer)));
        accept(CTABLEBRACKET);
        return std::make_unique<Variable>("copy",std::move(nodes),1);//chyba zle
    }
    return std::make_unique<Variable>(*x);

}

std::unique_ptr<Condition> Parser::condition() {
    bool negative=false;
    if(symbol==EXCLAMATION) negative=true;
    std::list<std::unique_ptr<Condition>> conditions;
    std::unique_ptr<Expression> expressionLeft=std::move(expression());
    if(relativeOperator.find(symbol)!=relativeOperator.end()){
        SymbolType relativesymbol = token.getType();
        nextSymbol();
        std::unique_ptr<Expression> expressionRight=std::move(expression());
        return std::make_unique<Condition>(std::move(expressionLeft),std::move(expressionRight),relativesymbol,negative);
    }
    return std::make_unique<Condition>(std::move(expressionLeft),false,ORSY,negative);
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

Parser::~Parser() {
    delete scope;
    for(auto &i : toDelete)
        delete i;
}
