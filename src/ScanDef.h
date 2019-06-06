//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SCANDEF_H
#define DOMINO_SCANDEF_H

 enum SymbolType
 {
     FUNC, //FUNCTION 0
     WRITEIN, //1
     WRITEOUT, //2
     WHILE, //3
     FOR, //4
     IF, //5
     ELSE, //6
     MAIN, //7
     EOFSYMBOL, //8
     AND, //9
     OR, //10
     RETURN, //11
     INTSYMBOL, //12
     BOOLEANSYMBOL, //13
     STRINGSYMBOL, //14
     FLOATSYMBOL, //15
     CHARSYMBOL, //16
     RATIONALSYMBOL, //17
     VOIDSYMBOL, //18
     SHORTSYMBOL, //19
     COLON, //20
     INPUTSTREAM, // >> 21
     OUTPUTSTREAM,  // << 22
     ADD, //23
     SUBTRACT, //24
     DIVIDE, //25
     MULTIPLY, //26
     REST, //27
     MOREOREQUAL, //28
     LESSOREQUAL, //29
     DIFFERENT, //30
     MORE, //31
     LESS, //32
     ASSIGN, //33
     EQUALS,// == 34
     OTABLEBRACKET, //35
     CTABLEBRACKET, //36
     OROUNDBRACKET,//= ‘(‘ 37
     CROUNDBRACKET,//=’) 38
     OPENBRACKET, //='{'39
     CLOSEBRACKET, //='}'40
     SEMICOLON, //41
     COMA, //42
     DOT, //43
     EXCLAMATION, //44
     TRUE,
     FALSE,
     OTHERS, //45
     INTCONST, //46
     CHARCONST, //47
     IDENTIFIER, //48
     RATIONALCONST, //49
     FLOATCONST, //50
     STRINGCONST, //51
     ENDOFTEXT,//52
     MAXSYM
 };

enum ScanErrors{ CARCONSTWRONG, ICONST2BIG, WRONGINTVALUE, WRONGRATIONALVALUE, WRONGFLOATVALUE} ;




#endif //DOMINO_SCANDEF_H