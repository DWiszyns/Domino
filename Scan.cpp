//
// Created by dominik on 4/6/19.
//

#include <climits>
#include <unordered_map>
#include <cstring>
#include "Scan.h"

char *AT[MAXSYM + 1] =    // Atomy tekstowo
        {
                "beg", "rd",  "wrt", "if", "whl",
                "end", "thn", "els", "do", "var",
                "not", "and", "div", "or", "arr",
                "of",  "prg", "prc",
                "id",  "ico", "cco", "*",  "+",  "-",
                "<",   "<=",  ">",   ">=", "<>", "=",
                "(",   ")",   "[",   "]",  ";",  ":",
                ":=",  "..",  ".",   ",",  "???"
        };
std::unordered_map <std::string, SymType > Scan::KT= {
// Keyword       Atom         hash(keyword)
//-------------------------------------------
        { "rational",   RATIONALSY  },  //  0
        { "writein",    WRITEIN},  //  1
        { "writeout",   WRTIEOUT},  //  2
        { "function",   FUNCSY },  //  3
        { "int",        INTSY  },  //  4
        { "string",     STRINGSY  },  //  5
        { "float",      FLOATSY  },  //  6
        { "short",      SHORTSY  },  //  7
        { "char",       CHARSY }, //8
        { "if",         IFSY   },  //  9
        { "while",      WHILESY},  //  10
        { "for",        FORSY },  //  11
        { "return",     RETURNSY },  //  12
        { "else",       ELSESY } ,  //  13
        { "main",       MAINSY} , // 14
        { "void",       VOIDSY}, // 15
        { "boolean",     BOOLEANSY} //16
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

// cd1 NextSymbol()
//---IDENTYFIKATOR LUB S
    if(isalpha(c))
    { unsigned int len=0, h;
        do
        { if(len<MAXIDLEN) spell[len++]=c;
            nextC();
        } while(isalnum(c));
        spell[len]='\0';
        if(KT.count(spell)!=0)
            return KT[spell];
        else return IDENTIFIER;
    }
    else
// cd2 NextSymbol()
//---STA
    if(isdigit(c))
    { int big; long l=0;
        do
        { l   = l*10+(c-'0');
            big = l>INT_MAX;
            nextC();
        } while(isdigit(c));
        intconstant = (int)l;
        if(big) scanError(ICONST2BIG);
        return INTCONST;
    }
    else

// cd3 NextSymbol() ---Pozosta
    switch(c)
    {
        case '"':
            nextC();
            if(c=='"')
            { nextC();
                if(c!='"') scanError(CARCONSTWRONG);
            }
            intconstant=c; nextC();
            if(c!='"') scanError(CARCONSTWRONG);
            else nextC();
            return CHARCONST;
// cd4 NextSymbol()
//----Operatory 2 i 1 znakowe
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

void Scan::scanError(ScanErrors error) {
    static const char *ScnErr[] =
            { "Przekroczony zakres",    // 0
              "Bledna stala znakowa"// 1
            };
    if(mt) src.Error(ec, atompos, mt, at);
    else src.Error(FirstLexErr + ec, atompos,ScnErr[ec]);

}




