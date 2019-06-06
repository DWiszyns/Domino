//
// Created by dominik on 4/11/19.
//

#include "Source.h"
#include "Scanner.h"
#include "Token.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(ScanTest)

BOOST_AUTO_TEST_CASE(function_symbol_test){
        Source src("function x():void{} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL( FUNC, c.getType());
}

BOOST_AUTO_TEST_CASE(identifier_symbol_test){
        Source src("x():void{} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(IDENTIFIER, c.getType());
    }

BOOST_AUTO_TEST_CASE(oroundbracket_symbol_test){
        Source src("():void{} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(OROUNDBRACKET, c.getType());
}

BOOST_AUTO_TEST_CASE(croundbracket_symbol_test){
        Source src("):void{} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(CROUNDBRACKET, c.getType());
}

BOOST_AUTO_TEST_CASE(colon_symbol_test){
        Source src(":void{} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(COLON, c.getType());
}

BOOST_AUTO_TEST_CASE(void_symbol_test){
        Source src("void{} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(VOIDSYMBOL, c.getType());
}

BOOST_AUTO_TEST_CASE(openbracket_symbol_test){
        Source src("{} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(OPENBRACKET, c.getType());
}

BOOST_AUTO_TEST_CASE(closebracket_symbol_test){
        Source src("} function main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(CLOSEBRACKET, c.getType());
}

BOOST_AUTO_TEST_CASE(main_symbol_test){
        Source src("main():void{}",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(MAIN, c.getType());
}

BOOST_AUTO_TEST_CASE(rational_symbol_test){
        Source src("rational",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(RATIONALSYMBOL, c.getType());
}

BOOST_AUTO_TEST_CASE(float_symbol_test){
        Source src("float",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(FLOATSYMBOL, c.getType());
}

BOOST_AUTO_TEST_CASE(int_symbol_test){
        Source src("int",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(INTSYMBOL, c.getType());
}

BOOST_AUTO_TEST_CASE(string_symbol_test){
        Source src("string",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(STRINGSYMBOL, c.getType());
}

BOOST_AUTO_TEST_CASE(char_symbol_test){
        Source src("char",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(CHARSYMBOL, c.getType());
}

BOOST_AUTO_TEST_CASE(otablebracket_symbol_test){
        Source src("[",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(OTABLEBRACKET, c.getType());
}

BOOST_AUTO_TEST_CASE(ctablebracket_symbol_test){
        Source src("]",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(CTABLEBRACKET, c.getType());
}

BOOST_AUTO_TEST_CASE(coma_symbol_test){
        Source src(",",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(COMA, c.getType());
}

BOOST_AUTO_TEST_CASE(writein_symbol_test){
        Source src("writein",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(WRITEIN, c.getType());
}

BOOST_AUTO_TEST_CASE(writeout_symbol_test){
        Source src("writeout",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(WRITEOUT, c.getType());
}

BOOST_AUTO_TEST_CASE(outputstream_symbol_test){
        Source src("<<",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(OUTPUTSTREAM, c.getType());
}

BOOST_AUTO_TEST_CASE(inputstream_symbol_test){
        Source src(">>",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(INPUTSTREAM, c.getType());
}

BOOST_AUTO_TEST_CASE(semicolon_symbol_test){
        Source src(";",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(SEMICOLON, c.getType());
}

BOOST_AUTO_TEST_CASE(plus_symbol_test){
        Source src("+",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(ADD, c.getType());
}

BOOST_AUTO_TEST_CASE(minus_symbol_test){
        Source src("-",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(SUBTRACT, c.getType());
}

BOOST_AUTO_TEST_CASE(multiply_symbol_test){
        Source src("*",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(MULTIPLY, c.getType());
}

BOOST_AUTO_TEST_CASE(divide_symbol_test){
        Source src("/",true);
        Scanner scan(src);
        Token c = scan.nextToken();
        BOOST_CHECK_EQUAL(DIVIDE, c.getType());
}



BOOST_AUTO_TEST_SUITE_END()