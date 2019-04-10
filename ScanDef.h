//
// Created by dominik on 4/6/19.
//

#ifndef DOMINO_SCANDEF_H
#define DOMINO_SCANDEF_H
/*enum SymType    // Atomy leksykalne Mini Pascal'a
{
    beginsy,  readsy,  wri,
    tesy, ifsy,  whilesy,
    endsy,    thensy,  elsesy,  dosy,  varsy,
    notop,    andop,
    divop,   orop,  arraysy,
    ofsy,     progsy,  funcsy,    // Keywords
    NKEYS,    MAXKEY=funcsy,
    ident,    intconst,cha,
    rconst,times,plus,  minus,
    ltop,     leop,    gtop,
    geop, neop,  eqop,
    lparent,  rparent, lbracket, rbracket,
    semicolon,colon,   becomes,
    thru,   period,
    coma,    others,   MAXSYM=others+1
};*/
 enum SymType
 {
     FUNCSY, //FUNCTION
     WRITEIN, WRTIEOUT, WHILESY, FORSY,
     IFSY, ELSESY, MAINSY, EOFSY,
     ANDSY, ORSY, RETURNSY, VOIDSY,
     STRINGSY, FLOATSY, RATIONALSY, INTSY,
     SHORTSY, CHARSY, BOOLEANSY, COLON,
     INPUTSTREAM, // >>
     OUTPUTSTREAM,  // <<
     ADDSY, SUBTRACTSY, DIVIDESY, MULTIPLYSY,
     RESTSY, MOREOREQUAL, LESSOREQUAL,
     DIFFERENT, MORE, LESS, ASSIGN,
     EQUALS,// ==
     OTABLEBRACKET,CTABLEBRACKET,
     OROUNDBRACKET,//= ‘(‘
     CROUNDBRACKET,//=’)
     OPENBRACKET, //='}'
     CLOSEBRACKET, //='}'
     SEMICOLON, COMA, DOT, EXCLAMATION, OTHERS,
     INTCONST, CHARCONST, IDENTIFIER
 };

enum ScanErrors{ CARCONSTWRONG=1, ICONST2BIG };
#endif //DOMINO_SCANDEF_H
