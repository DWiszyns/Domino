//
// Created by dominik on 5/8/19.
//

#include "Source.h"
#include "Scanner.h"
#include "Parser.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(ParserTest)

BOOST_AUTO_TEST_CASE(basic_test){
        Source src("function x():void{} function main():void{}",true);
        Scanner scan(src);
        Parser parser(scan);
        std::unique_ptr<Program> program=parser.parse();
        BOOST_CHECK_NO_THROW(program->execute());
}

BOOST_AUTO_TEST_CASE(dividing_by_zero){
    Source src("function x():void{} function main():void{int x = 1/0;}",true);
    Scanner scan(src);
    Parser parser(scan);
    std::unique_ptr<Program> program=parser.parse();
    BOOST_CHECK_THROW(program->execute(),std::runtime_error);
}

BOOST_AUTO_TEST_CASE(basic_assignment){
    Source src("function x():void{} function main():void{int x=2+3;}",true);
    Scanner scan(src);
    Parser parser(scan);
    std::unique_ptr<Program> program=parser.parse();
    BOOST_CHECK_NO_THROW(program->execute());
}

BOOST_AUTO_TEST_CASE(variable_not_declared){
    Source src("function x():void{} function main():void{int x=2+a;}",true);
    Scanner scan(src);
    Parser parser(scan);
    BOOST_CHECK_THROW(parser.parse(),std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()