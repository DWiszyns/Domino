//
// Created by dominik on 4/6/19.
//

#include <climits>
#include <unordered_map>
#include <cstring>
#include "Scanner.h"
#include "Token.h"

std::string atomsTable[55]= {
        "function",//FUNC, //FUNCTION 0
        "writein",//        WRITEIN, //1
        "writeout",//        WRITEOUT, //2
        "while",//        WHILE, //3
        "for",//        FOR, //4
        "if",//        IF, //5
        "else",//        ELSE, //6
        "main",//        MAIN, //7
        "EOF",//        EOFSYMBOL, //8
        "&&",//        AND, //9
        "||",//        OR, //10
        "return",//        RETURN, //11
        "void",//        VOIDSYMBOL, //12
        "string",//        STRINGSYMBOL, //13
        "float",//        FLOATSYMBOL, //14
        "rational",//        RATIONALSYMBOL, //15
        "int",//        INTSYMBOL, //16
        "short",//        SHORTSYMBOL, //17
        "char",//        CHARSYMBOL, //18
        "boolean",//        BOOLEANSYMBOL, //19
        ":",//        COLON, //20
        ">>",//        INPUTSTREAM, // >> 21
        "<<",//        OUTPUTSTREAM,  // << 22
        "+",//        ADD, //23
        "-",//        SUBTRACT, //24
        "/",//        DIVIDE, //25
        "*",//        MULTIPLY, //26
        "%",//        REST, //27
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
        { "rational",   RATIONALSYMBOL},
        { "writein",    WRITEIN},  
        { "writeout",   WRITEOUT},
        { "function",   FUNC },
        { "int",        INTSYMBOL  },
        { "string",     STRINGSYMBOL  },
        { "float",      FLOATSYMBOL  },
        { "short",      SHORTSYMBOL  },
        { "char",       CHARSYMBOL },
        { "if",         IF   },
        { "while",      WHILE},
        { "for",        FOR },
        { "return",     RETURN },
        { "else",       ELSE } ,
        { "main",       MAIN} ,
        { "void",       VOIDSYMBOL},
        { "boolean",     BOOLEANSYMBOL}
};

Scanner::Scanner(Source &source): src(source) {
    atomLine=1;
    atomPos=0;
}

Scanner::~Scanner() {

}

Token Scanner::createString(){
    unsigned int len=0, h;
        while(isalnum(c)){ 
            if(len<MAXIDLEN) spell[len++]=c;
            nextChar();
        }
        spell[len]='\0';
        if(keyWordHashMap.count(spell)!=0)
            return Token(keyWordHashMap[spell],spell);
        else return Token(IDENTIFIER,spell);
}

Token Scanner::getFirstUsefulChar(){
    while(isspace(c) || c=='/'){   
        while(isspace(c)) nextChar();
        if(c==EOF) return Token(EOFSYMBOL,"EOF");
        if(c=='/')
        {
            nextChar();
            if(c=='/'){
                while(c!='\n')
                    nextChar();
            } else return Token(DIVIDE,"/");
        }
        if(c=='\0') return Token(ENDOFTEXT,"\0");
    }
    return Token(MAXSYM,"");
}

Token Scanner::createNumber(){
    int big; long l=0;
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
                std::string floatConstant=std::to_string(l)+'.'+std::to_string(h)+'f';
                nextChar();
                return Token(FLOATCONST,floatConstant);//zle
            }
            else if (c=='r') {
                std::string rationalConstant=std::to_string(l)+'.'+std::to_string(h)+'r';
                nextChar();
                return Token(RATIONALCONST,rationalConstant);//zle
            }

        }
        else {
            std::string intconstant = std::to_string(l);
            if (big) scanError(ICONST2BIG, intconstant);
            return Token(INTCONST,intconstant);
        }
}

Token Scanner::createStringInQuotes(){
    nextChar();
    unsigned int len = 0;
    std::string myString;
    while (c != '"') {
        if (c!='\''){
            if (len < MAXIDLEN) spell[len++] = c;
            nextChar();
        }
        else scanError(CARCONSTWRONG, spell);
    }
    spell[len] = '\0';
    if (len == 1) {
        nextChar();
        return Token(CHARCONST,spell);
    }
    else
        myString=spell;
        nextChar();
    return Token(STRINGCONST,spell);

}

Token Scanner::createTwoSignOperator(){
    switch(c){
        case '=':
            nextChar();
            if(c=='=') { nextChar(); return Token(EQUALS,atomsTable[ASSIGN]); }
            else return Token(ASSIGN,atomsTable[ASSIGN]);
        case '&':
            nextChar();
            if(c=='&') { nextChar(); return Token(AND,atomsTable[AND]);}
            else return Token(OTHERS,atomsTable[OTHERS]);
        case '<':
            nextChar();
            if(c=='=') { nextChar(); return Token(LESSOREQUAL,atomsTable[LESSOREQUAL]);}
            else if(c=='>') { nextChar(); return Token(DIFFERENT,atomsTable[DIFFERENT]); }
            else if(c=='<') { nextChar(); return Token(OUTPUTSTREAM,atomsTable[OUTPUTSTREAM]); }
            else return Token(LESS,atomsTable[LESS]);
        case '>':
            nextChar();
            if(c=='=') { nextChar(); return Token(MOREOREQUAL,atomsTable[MOREOREQUAL]); }
            else if(c=='>') { nextChar(); return Token(INPUTSTREAM,atomsTable[INPUTSTREAM]); }
            else return Token(MORE,atomsTable[MORE]);
        case '|':
            nextChar();
            if(c=='|') { nextChar(); return Token(OR,atomsTable[OR]);}
            else return Token(OTHERS,atomsTable[OTHERS]);
        case '!':
            nextChar();
            if(c=='=') { nextChar(); return Token(DIFFERENT,atomsTable[DIFFERENT]); }
            else return Token(EXCLAMATION,atomsTable[EXCLAMATION]);
    }
}
Token Scanner::createOneSignOperator(){
    switch(c){
        case '+':
            nextChar(); return Token(ADD,atomsTable[ADD]);
        case '-':
            nextChar(); return Token(SUBTRACT, atomsTable[SUBTRACT]);
        case '*':
            nextChar(); return Token(MULTIPLY,atomsTable[MULTIPLY]);
        case '%':
            nextChar(); return Token(REST,atomsTable[REST]);
        case '(':
            nextChar(); return Token(OROUNDBRACKET,atomsTable[OROUNDBRACKET]);
        case ')':
            nextChar(); return Token(CROUNDBRACKET,atomsTable[CROUNDBRACKET]);
        case '[':
            nextChar(); return Token(OTABLEBRACKET,atomsTable[OTABLEBRACKET]);
        case ']':
            nextChar(); return Token(CTABLEBRACKET,atomsTable[CTABLEBRACKET]);
        case ',':
            nextChar(); return Token(COMA,atomsTable[COMA]);
        case ';':
            nextChar(); return Token(SEMICOLON,atomsTable[SEMICOLON]);
        case ':':
            nextChar(); return Token(COLON,atomsTable[COLON]);
        case '.':
            nextChar(); return Token(DOT,atomsTable[DOT]);
        case '{':
            nextChar(); return Token(OPENBRACKET,atomsTable[OPENBRACKET]);
        case '}':
            nextChar(); return Token(CLOSEBRACKET,atomsTable[CLOSEBRACKET]);
        default :
            nextChar(); return Token(OTHERS,atomsTable[OTHERS]);
    }
}


Token Scanner::nextToken() {
    flushSpell();
    if(src.getTextLine()==1 && src.getTextPos()==0) nextChar();
    Token returned = getFirstUsefulChar();
    if(returned.getType()!=MAXSYM) return returned;
    atomLine=src.getTextLine();
    atomPos=src.getTextPos();
    if(isalpha(c)){
        returned=createString();
    }
    else if(isdigit(c)){ 
        returned=createNumber();
    }
    else switch(c)
    {
        case '"': {
            returned=createStringInQuotes();
            break;
        }
        case '=':case '&':case '<':
        case '>':case '|':case '!':{
            returned=createTwoSignOperator();
            break;
        }
        default :{
            returned=createOneSignOperator();
            break;
        }
    }
    return returned;
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

void Scanner::flushSpell() {
    for(int i=0;i<16;++i)
        spell[i]='\0';

}




