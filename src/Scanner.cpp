//
// Created by dominik on 4/6/19.
//

#include <climits>
#include <unordered_map>
#include <cstring>
#include "Scanner.h"


std::unordered_map <std::string, SymbolType > Scanner::KT= {
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

Scanner::Scanner(Source &source): src(source) {

}

Scanner::~Scanner() {

}

SymbolType Scanner::nextSymbol() {
    if(src.getTextLine()==1 && src.getTextPos()==0) nextChar();
    while(isspace(c) || c=='/')
    { while(isspace(c)) nextChar();// skip spaces
        if(c==EOF) return EOFSY;
        if(c=='/')
        {
            nextChar();
            if(c=='/'){
                while(c!='\n')
                    nextChar();
            } else return DIVIDESY;
        }
    }

    int line=src.getTextLine();
    int pos=src.getTextPos();

//---creating variable
    if(isalpha(c)){
        unsigned int len=0, h;
        while(isalnum(c))
        { 
            if(len<MAXIDLEN) spell[len++]=c;
            nextChar();
        }
        spell[len]='\0';
        if(KT.count(spell)!=0)
            return KT[spell];
        else return IDENTIFIER;
    }
    else
//---Numeric
    if(isdigit(c))
    { int big; long l=0;
        while(isdigit(c))
        { 
            l = l*10+(c-'0');
            big = l>INT_MAX;
            nextChar();
        }
        if(c=='.'){
            int big2; long h=0;
            nextChar();
            if(!isdigit(c)) {
                std::string intconstant = std::to_string(l);
                scanError(WRONGINTVALUE, intconstant);
            }
            while(isdigit(c)){
                h = h*10+(c-'0');
                big = h>SHRT_MAX;
                nextChar();
            }
            if(c=='f') return FLOATCONST;
            else if (c=='r') return RATIONALCONST;

        }
        else {
            std::string intconstant = std::to_string(l);
            if (big) scanError(ICONST2BIG, intconstant);
            return INTCONST;
        }
    }
    else

// cd3 NextSymbol() ---Rest of the signs
    switch(c)
    {
        case '"': {
            nextChar();
            unsigned int len = 0;
            while (c != '"') {
                if (c!='\'')
                {
                    if (len < MAXIDLEN) spell[len++] = c;
                    nextChar();
                }
                else scanError(CARCONSTWRONG, spell);
            }
            spell[len] = '\0';
            if (len == 1) {
                nextChar();
                return CHARCONST;
            }
            else nextChar();
            return STRINGCONST;
        }
// cd4 NextSymbol()
//---- 2 and 1 sign operators
        case '=':
            nextChar();
            if(c=='=') { nextChar(); return EQUALS; }
            else return ASSIGN;
        case '&':
            nextChar();
            if(c=='&') { nextChar(); return ANDSY;}
            else return OTHERS;
        case '<':
            nextChar();
            if(c=='=') { nextChar(); return LESSOREQUAL;}
            else if(c=='>') { nextChar(); return DIFFERENT; }
            else if(c=='<') { nextChar(); return OUTPUTSTREAM; }
            else return LESS;
        case '>':
            nextChar();
            if(c=='=') { nextChar(); return MOREOREQUAL; }
            else if(c=='>') { nextChar(); return INPUTSTREAM; }
            else return MORE;
        case '|':
            nextChar();
            if(c=='|') { nextChar(); return ORSY;}
            else return OTHERS;
        case '!':
            nextChar();
            if(c=='=') { nextChar(); return DIFFERENT; }
            else return EXCLAMATION;
//----Operatory 1 znakowe
        case '+':
            nextChar(); return ADDSY;
        case '-':
            nextChar(); return SUBTRACTSY;
        case '*':
            nextChar(); return MULTIPLYSY;
        case '%':
            nextChar(); return RESTSY;
        case '(':
            nextChar(); return OROUNDBRACKET;
        case ')':
            nextChar(); return CROUNDBRACKET;
        case '[':
            nextChar(); return OTABLEBRACKET;
        case ']':
            nextChar(); return CTABLEBRACKET;
        case ',':
            nextChar(); return COMA;
        case ';':
            nextChar(); return SEMICOLON;
        case ':':
            nextChar(); return COLON;
        case '.':
            nextChar(); return DOT;
        case '{':
            nextChar(); return OPENBRACKET;
        case '}':
            nextChar(); return CLOSEBRACKET;
        default :
            nextChar(); return OTHERS;
    }
}

void Scanner::scanError(int ec, std::string word) {
    static const char *ScnErr[] ={
            "Wrong char value",// 0
            "Out of range"    // 1
            };
    src.error(word, atomLine, atomPos, ScnErr[ec]);
}




