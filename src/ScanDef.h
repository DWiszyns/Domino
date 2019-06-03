//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SCANDEF_H
#define DOMINO_SCANDEF_H

 enum SymbolType
 {
     FUNCSY, //FUNCTION 0
     WRITEIN, //1
     WRITEOUT, //2
     WHILESY, //3
     FORSY, //4
     IFSY, //5
     ELSESY, //6
     MAINSY, //7
     EOFSY, //8
     ANDSY, //9
     ORSY, //10
     RETURNSY, //11
     INTSY, //12
     BOOLEANSY, //13
     STRINGSY, //14
     FLOATSY, //15
     CHARSY, //16
     RATIONALSY, //17
     VOIDSY, //18
     SHORTSY, //19
     COLON, //20
     INPUTSTREAM, // >> 21
     OUTPUTSTREAM,  // << 22
     ADDSY, //23
     SUBTRACTSY, //24
     DIVIDESY, //25
     MULTIPLYSY, //26
     RESTSY, //27
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