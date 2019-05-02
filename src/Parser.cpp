//
// Created by dominik on 5/2/19.
//

#include "Parser.h"
#include "Synchronize.h"
#include <set>

//dafaq is EOS???
//dafaq is //??
Parser::Parser(Scanner &s): scanner(s)
{
    SymbolType multiplySymbols[] = {MULTIPLYSY,DIVIDESY};
    multiplyOperator.insert(multiplySymbols,multiplySymbols+1);
    SymbolType statementStartSymbols[] = {WRITEIN,WRTIEOUT,IFSY,WHILESY,FORSY,IDENTIFIER,FUNCSY,RETURNSY};
    statementStart.insert(statementStartSymbols,statementStartSymbols+7);

    stseq   = std::set<SymbolType>(IFSY,WHILESY,SEMICOLON);

    stiter   =std::set<SymbolType>(IFSY,WHILESY,SEMICOLON);

    statementSomething = std::set<SymbolType>(IDENTIFIER,INTCONST,CHARCONST,OROUNDBRACKET);

    multiplyOperator   = std::set<SymbolType>(MULTIPLYSY,DIVIDESY);
    factiter = statementSomething + multiplyOperator;
    SymbolType signSymbols[]={SUBTRACTSY, ADDSY};
    signs.insert(signSymbols,signSymbols+1);
    addOperator.insert(signSymbols,signSymbols+1);
    SymbolType logicalSymbols[]={EQUALS, LESSOREQUAL, LESS, MORE, MOREOREQUAL,DIFFERENT};
    logicalOperator.insert(logicalSymbols,logicalSymbols+5);
    back   = MAXSYM; // Znacznik braku atomu poprzedniego
    nextSymbol();         // Pobranie 1-go atomu
}

void Parser::Program(void)
// Program = "program" ident ';' Block '.' ;
{
    // t("Program",-1);
    accept(progsy);
    accept(IDENTIFIER);
    accept(SEMICOLON);
    Block(period);
}
void Parser::Block(const std::set<SymbolType>&  fs)???
// Block = VarPart ProcPart StmentPart ;
{
     // x("Block", fs);
    Synchronize s(std::set<SymbolType>(varsy,FUNCSY, beginsy,EOS), fs);
    if(!can_parse) return;
    VarPart(std::set<SymbolType>(procsy, beginsy, EOS));
    ProcPart(beginsy);
    //StatementPart(fs); nie wiem po co to
}

void Parser::VarPart(const std::set<SymbolType>&  fs)
{
    // x("VarPart", fs);
    Synchronize s(fs + varsy, fs);
    if(!can_parse) return;
    if(symbol==varsy)
    { accept(varsy);
        do
        {
            VarDeclaration(fs + SEMICOLON);
            accept(SEMICOLON);
        } while (symbol==IDENTIFIER);
    }
}

// VarDecl = ident { ',' ident } ':' Type ;
void Parser::VarDeclaration(const std::set<SymbolType>&  fs)
{
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

void Parser::Type(const std::set<SymbolType>&  fs)
{
    // x("Type", fs);
    Synchronize s(std::set<SymbolType>(i
    dent,arraysy,EOS), fs);
    if(!can_parse) return;
    if(symbol==ident) SimpleType(fs);
    else
// ArrayType
    {
        accept(arraysy);
        accept(lbracket);
        IndexRange(fs + std::set<SymbolType>(rbracket, ofsy, EOS));
        accept(rbracket);
        accept(ofsy);
        SimpleType(fs);
    }
}

// SimpType = TypeIdent ;
void Parser::SimpleType(const std::set<SymbolType>& fs)
{
    // x("SimType", fs);
    Synchronize s(this, IDENTIFIER, fs);
    if(can_parse) accept(IDENTIFIER);
}
//IndexRange = intconst '..' intconst ;
void Parser::IndexRange (const std::set<SymbolType> & fs)
{
    // x("IndRange", fs);
    Synchronize s(this, std::set<SymbolType>
            (INTCONST, thru), fs);
    if(can_parse)
    {
        accept(INTCONST);
        accept(thru);
        accept(INTCONST);
    }
}

// ProcPart = { ProcDecl ';' } ;
void Parser::ProcPart(const std::set<SymbolType>&  fs)
{
    // x("FunctionPart", fs);
    Synchronize s(this, fs+FUNCSY, fs);
    if(!can_parse) return;
    while(symbol==FUNCSY)
    {
        functionDeclaration(fs + std::set<SymbolType>(SEMICOLON, FUNCSY));
        accept (SEMICOLON);
    }
}
// ProcDecl = "procedure" ident ';' Block ;
void Parser::functionDeclaration(const std::set<SymbolType> &fs)
{
    // x("FuncDeclaration", fs);
    Synchronize s(this, fs + FUNCSY, fs);
    if(!can_parse) return;
    accept(FUNCSY);
    accept(IDENTIFIER);
    accept(SEMICOLON);
    Block(fs);
}

// StmentPart = CompStment ;
// Stment     = SimpStment | StructStment ;
// SimpStment = Assignment | ProcStment |ReadStment | WriteStment ;
// CompStment = "begin" Stment { ';' Stment } "end" ;
// StructStment  = CompStment |IfStment | WhileStment ;

//Nie wiem po co to
/*void Parser::StatementPart(const std::set<SymbolType>&  fs)
{
    // x("StatPart", fs);
    Synchronize s(beginsy, fs);
    if(!can_parse) return;
    CompoundStatement(fs);
}*/

void Parser::Statement(const std::set<SymbolType>&  fs)
{
    // x("Statemet", fs);
    Synchronize s(this, statementStart, fs);
    if(!can_parse) return;
    switch(symbol)
    {
        //case BEGIN: CompoundStatement(fs); break;
        case IFSY:    IfStatement(fs);       break;
        case WHILESY: WhileStatement(fs);    break;
        case WRITEIN:  ReadStatement(fs);     break;
        case WRTIEOUT: WriteStatement(fs);    break;
        case IDENTIFIER :  // Procedura albo przypisanie
// ... na podstawie atrybutów nazwy.
            nextSymbol(); // Symbol za ident
            if(!fs.find(symbol))   // To nie wywolananie
                        {
                            symBack(IDENTIFIER);      // Wycofaj symbol
                            Assignment(fs);
                        }
    }}
//Nie wiem po ci to
/*void Parser::CompoundStatement(const std::set<SymbolType>&  fs)
{
    // x("CompStmt", fs);
    Synchronize s(beginsy, fs);
    if(!can_parse) return;
    accept(beginsy);
    Statement(stseq+fs);
    while(stiter.find(symbol))
    {
        accept(SEMICOLON);
        Statement(stseq+fs);
    }
    accept(endsy);
}
 */

void Parser::IfStatement(const std::set<SymbolType>&  fs)
{
// Synchronizacja w procedurze Statement()
    // t("IfSt", -1);
    accept(IFSY);
    Expression(fs + std::set<SymbolType>(ELSESY));
    Statement(fs + ELSESY);
    if (symbol == ELSESY)
    {
        accept(ELSESY);
        Statement(fs);
    }
}

void Parser::WhileStatement(const std::set<SymbolType>&  fs)
{
// Synchronizacja w procedurze Statement()
    // t("WhileSt", -1);
    accept(WHILESY);
    Expression(fs /*+ dosy*/);
    //accept(dosy);
    Statement(fs);
}
void Parser::Assignment(const std::set<SymbolType>&  fs)
{
// Synchronizacja w procedurze Statement()
    // t("Assgn", -1);
    Variable(fs + ASSIGN);
    accept(ASSIGN);
    Expression(fs);
}

void Parser::ReadStatement(const std::set<SymbolType>&  fs)
{
// Synchronizacja w procedurze Statement()
    // t("ReadSt", -1);
    accept(WRTIEOUT);
    accept(OROUNDBRACKET);
    InputVariable(fs);
    while (symbol==COMA)
    {
        accept(COMA);
        InputVariable(fs);
    }
    accept(CROUNDBRACKET);
}

void Parser::WriteStatement(const std::set<SymbolType>&  fs)
{
// Synchronizacja w procedurze Statement()
    // t("WriteSt", -1);
    accept(WRITEIN);
    accept(OROUNDBRACKET);
    OutputValue(fs);
    while (symbol==COMA)
    {
        accept(COMA);
        OutputValue(fs);
    }
    accept(CROUNDBRACKET);
}

// Expr = SimpExpr | SimpExpr RelOp SimpExpr ;
void Parser::Expression(const std::set<SymbolType>&  fs)
{ // Synchronizacja odrocz
    SimpleExpression();
    // t("Expr", -1);
    SimpleExpression(fs + logicalOperator);
    if(logicalOperator.find(symbol))
    { nextSymbol();
        SimpleExpression(fs);
    }
}
// SimpExpr = Sign Term { AddOp Term } ;
void Parser::SimpleExpression(const std::set<SymbolType>&  fs)
{
    // x("SimExp", fs);
    Synchronize s(statementSomething+signs, fs);
    if(!can_parse) return;
    if(signs.find(symbol)) nextSymbol();
    Term(fs + addOperator);
    while(addOperator.find(symbol))
    {
        nextSymbol();
        Term(fs+addOperator);
    }
}



