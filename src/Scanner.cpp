//
// Created by dominik on 4/6/19.
//

#include <climits>
#include <unordered_map>
#include <cstring>
#include "Scanner.h"

std::string atomsTable[55]= {
        "function",//FUNCSY, //FUNCTION 0
        "writein",//        WRITEIN, //1
        "writeout",//        WRTIEOUT, //2
        "while",//        WHILESY, //3
        "for",//        FORSY, //4
        "if",//        IFSY, //5
        "else",//        ELSESY, //6
        "main",//        MAINSY, //7
        "EOF",//        EOFSY, //8
        "&&",//        ANDSY, //9
        "||",//        ORSY, //10
        "return",//        RETURNSY, //11
        "void",//        VOIDSY, //12
        "string",//        STRINGSY, //13
        "float",//        FLOATSY, //14
        "rational",//        RATIONALSY, //15
        "int",//        INTSY, //16
        "short",//        SHORTSY, //17
        "char",//        CHARSY, //18
        "boolean",//        BOOLEANSY, //19
        ":",//        COLON, //20
        ">>",//        INPUTSTREAM, // >> 21
        "<<",//        OUTPUTSTREAM,  // << 22
        "+",//        ADDSY, //23
        "-",//        SUBTRACTSY, //24
        "/",//        DIVIDESY, //25
        "*",//        MULTIPLYSY, //26
        "%",//        RESTSY, //27
        ">=",//        MOREOREQUAL, //28
        "<=",//        LESSOREQUAL, //29
        "!=",//        DIFFERENT, //30
        ">",//        MORE, //31
        "<",//        LESS, //32
        "=",//        ASSIGN, //33
        "==",//        EQUALS,// == 34
        "[",//        OTABLEBRACKET, //35
        "]",//        CTABLEBRACKET, //36
        "(",//        OROUNDBRACKET,//= ‘(‘ 37
        ")",//        CROUNDBRACKET,//=’) 38
        "{",//        OPENBRACKET, //='{'39
        "}",//        CLOSEBRACKET, //='}'40
        ";",//        SEMICOLON, //41
        ",",//        COMA, //42
        ".",//        DOT, //43
        "!",//        EXCLAMATION, //44
        "true",//TRUE
        "false",//FALSE
        "others",//        OTHERS, //47
        "intconst",//        INTCONST, //48
        "charconst",//        CHARCONST, //49
        "identifier",//        IDENTIFIER, //50
        "rationalconst",//        RATIONALCONST, //51
        "floatconst",//        FLOATCONST, //52
        "stringconst",//        STRINGCONST, //53
        "end of text"
//        MAXSYM
};

std::unordered_map <std::string, SymbolType > Scanner::keyWordHashMap= {
        { "rational",   RATIONALSY},
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
    atomLine=1;
    atomPos=0;

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
        if(c=='\0') return ENDOFTEXT;
    }

    atomLine=src.getTextLine();
    atomPos=src.getTextPos();

//---creating variable
    if(isalpha(c)){
        unsigned int len=0, h;
        while(isalnum(c))
        { 
            if(len<MAXIDLEN) spell[len++]=c;
            nextChar();
        }
        spell[len]='\0';
        if(keyWordHashMap.count(spell)!=0)
            return keyWordHashMap[spell];
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
            if(c=='f') {
                nextChar();
                return FLOATCONST;
            }
            else if (c=='r') {
                nextChar();
                return RATIONALCONST;
            }

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

void Scanner::scanError(SymbolType symbol, std::string word) {
    src.error(word, atomsTable[symbol],atomLine,atomPos);
}




