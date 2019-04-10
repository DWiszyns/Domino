//
// Created by dominik on 4/6/19.
//

#include <climits>
#include <unordered_map>
#include <cstring>
#include "Scan.h"


std::unordered_map <std::string, SymType > Scan::KT= {
// Keyword       Atom         
//-------------------------------------------
        { "rational",   RATIONALSY  }, 
        { "writein",    WRITEIN},  
        { "writeout",   WRTIEOUT},  
        { "function",   FUNCSY }, 
        { "int",        INTSY  }, 
        { "string",     STRINGSY  }, 
        { "float",      FLOATSY  },  
        { "short",      SHORTSY  }, 
        { "char",       CHARSY }, 
        { "if",         IFSY   },  
        { "while",      WHILESY},  
        { "for",        FORSY },  
        { "return",     RETURNSY }, 
        { "else",       ELSESY } , 
        { "main",       MAINSY} , 
        { "void",       VOIDSY},
        { "boolean",     BOOLEANSY} 
};

Scan::Scan(Source &source): src(source) {

}

Scan::~Scan() {

}

SymType Scan::nextSymbol() {

    while(isspace(c) || c=='/')
    { while(isspace(c)) nextC();// skip spaces
        if(c==EOF) return EOFSY;
        if(c=='/')  // comments
        {
            nextC();
            if(c=='/'){
                while(c!='\n')
                    nextC();
            } else return DIVIDESY;
        }
    }

    int line=src.getTextLine();
    int pos=src.getTextPos();

//---creating variable
    if(isalpha(c)){
        unsigned int len=0, h;
        while(isalnum(c));
        { 
            if(len<MAXIDLEN) spell[len++]=c;
            nextC();
        }
        spell[len]='\0';
        if(KT.count(spell)!=0)
            return KT[spell];
        else return IDENTIFIER;
    }
    else
//---INT
    if(isdigit(c))
    { int big; long l=0;
        while(isdigit(c));
        { 
            l = l*10+(c-'0');
            big = l>INT_MAX;
            nextC();
        }
        std::string intconstant = std::to_string(l);
        if(big) scanError(ICONST2BIG,intconstant);
        return INTCONST;
    }
    else

// cd3 NextSymbol() ---Rest of the signs
    switch(c)
    {
        case '"':
            nextC();
            if(c=='"')
            { nextC();
                if(c!='"') scanError(CARCONSTWRONG,"\"\"\"");
            }
            intconstant=c; nextC();
            unsigned int len=0;
            while(c!='"'){
                while(isalnum(c));
                { 
                    if(len<MAXIDLEN) spell[len++]=c;
                    nextC();
                }
                spell[len]='\0';
            }
            if(len==0)
            scanError(CARCONSTWRONG,"\"\"\"");
            else nextC();
            return CHARCONST;
// cd4 NextSymbol()
//---- 2 and 1 sign operators
        case '=': nextC();
            if(c=='=') {nextC(); return EQUALS; }
            else return ASSIGN;
        case '&': nextC();
            if(c=='&') { nextC(); return ANDSY;}
            else return OTHERS;
        case '<': nextC();
            if(c=='=') { nextC(); return LESSOREQUAL;}
            else if(c=='>') { nextC(); return DIFFERENT; }
            else if(c=='<') { nextC(); return OUTPUTSTREAM; }
            else return LESS;
        case '>': nextC();
            if(c=='=') { nextC(); return MOREOREQUAL; }
            else if(c=='>') { nextC(); return INPUTSTREAM; }
            else return MORE;
        case '|': nextC();
            if(c=='|') { nextC(); return ORSY;}
            else return OTHERS;
        case '!': nextC();
            if(c=='=') { nextC(); return DIFFERENT; }
            else return EXCLAMATION;
//----Operatory 1 znakowe
        case '+': nextC(); return ADDSY;
        case '-': nextC(); return SUBTRACTSY;
        case '*': nextC(); return MULTIPLYSY;
        case '%': nextC(); return RESTSY;
        case '(': nextC(); return OROUNDBRACKET;
        case ')': nextC(); return CROUNDBRACKET;
        case '[': nextC(); return OTABLEBRACKET;
        case ']': nextC(); return CTABLEBRACKET;
        case ',': nextC(); return COMA;
        case ';': nextC(); return SEMICOLON;
        case ':': nextC(); return COLON;
        case '.': nextC(); return DOT;
        case '{': nextC(); return OPENBRACKET;
        case '}': nextC(); return CLOSEBRACKET;
        default : nextC(); return OTHERS;
    }
}

void Scan::scanError(int ec, std::string word) {
    static const char *ScnErr[] ={
            "Wrong char value",// 0
            "Out of range"    // 1
            };
    src.Error(word, atomLine, atomPos, ScnErr[ec]);
}




