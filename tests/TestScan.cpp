//
// Created by dominik on 4/11/19.
//

#include "Source.h"
#include "Scanner.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(ScanTest)

BOOST_AUTO_TEST_CASE(function_symbol_test){
        Source src("function x():void{} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL( FUNCSY, c );
}

BOOST_AUTO_TEST_CASE(identifier_symbol_test){
        Source src("x():void{} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(IDENTIFIER, c );
    }

BOOST_AUTO_TEST_CASE(oroundbracket_symbol_test){
        Source src("():void{} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(OROUNDBRACKET, c );
}

BOOST_AUTO_TEST_CASE(croundbracket_symbol_test){
        Source src("):void{} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(CROUNDBRACKET, c );
}

BOOST_AUTO_TEST_CASE(colon_symbol_test){
        Source src(":void{} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(COLON, c );
}

BOOST_AUTO_TEST_CASE(void_symbol_test){
        Source src("void{} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(VOIDSY, c );
}

BOOST_AUTO_TEST_CASE(openbracket_symbol_test){
        Source src("{} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(OPENBRACKET, c );
}

BOOST_AUTO_TEST_CASE(closebracket_symbol_test){
        Source src("} function main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(CLOSEBRACKET, c );
}

BOOST_AUTO_TEST_CASE(main_symbol_test){
        Source src("main():void{}",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(MAINSY, c );
}

BOOST_AUTO_TEST_CASE(rational_symbol_test){
        Source src("rational",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(RATIONALSY, c );
}

BOOST_AUTO_TEST_CASE(float_symbol_test){
        Source src("float",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(FLOATSY, c );
}

BOOST_AUTO_TEST_CASE(int_symbol_test){
        Source src("int",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(INTSY, c );
}

BOOST_AUTO_TEST_CASE(string_symbol_test){
        Source src("string",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(STRINGSY, c );
}

BOOST_AUTO_TEST_CASE(char_symbol_test){
        Source src("char",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(CHARSY, c );
}

BOOST_AUTO_TEST_CASE(otablebracket_symbol_test){
        Source src("[",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(OTABLEBRACKET, c );
}

BOOST_AUTO_TEST_CASE(ctablebracket_symbol_test){
        Source src("]",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(CTABLEBRACKET, c );
}

BOOST_AUTO_TEST_CASE(coma_symbol_test){
        Source src(",",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(COMA, c );
}

BOOST_AUTO_TEST_CASE(writein_symbol_test){
        Source src("writein",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(WRITEIN, c );
}

BOOST_AUTO_TEST_CASE(writeout_symbol_test){
        Source src("writeout",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(WRITEOUT, c );
}

BOOST_AUTO_TEST_CASE(outputstream_symbol_test){
        Source src("<<",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(OUTPUTSTREAM, c );
}

BOOST_AUTO_TEST_CASE(inputstream_symbol_test){
        Source src(">>",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(INPUTSTREAM, c );
}

BOOST_AUTO_TEST_CASE(semicolon_symbol_test){
        Source src(";",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(SEMICOLON, c );
}

BOOST_AUTO_TEST_CASE(plus_symbol_test){
        Source src("+",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(ADDSY, c );
}

BOOST_AUTO_TEST_CASE(minus_symbol_test){
        Source src("-",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(SUBTRACTSY, c );
}

BOOST_AUTO_TEST_CASE(multiply_symbol_test){
        Source src("*",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(MULTIPLYSY, c );
}

BOOST_AUTO_TEST_CASE(divide_symbol_test){
        Source src("/",true);
        Scanner scan(src);
        int c = scan.nextSymbol();
        BOOST_CHECK_EQUAL(DIVIDESY, c );
}



BOOST_AUTO_TEST_SUITE_END()