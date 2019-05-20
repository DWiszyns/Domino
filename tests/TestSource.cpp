//
// Created by dominik on 4/10/19.
//

/*#define BOOST_TEST_MODULE source_test
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN*/

#include <iostream>
#include "Source.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(SourceTest)

BOOST_AUTO_TEST_CASE(check_next_char){
        Source src("function x():void{} function main():void{}",true);
        char c=src.nextChar();
        BOOST_CHECK_EQUAL( c, 'f' );
}

BOOST_AUTO_TEST_CASE(check_error1){
        Source src("function x():void{} function main():void{}",true);
        src.error("example","some atom",1,2);
        BOOST_CHECK_EQUAL( src.getErrorTotal(), 1 );
}

BOOST_AUTO_TEST_CASE(check_error2){
        Source src("function x():void{} function main():void{}",true);
        src.error("example",1,2,"some atom");
        BOOST_CHECK_EQUAL( src.getErrorTotal(), 1 );
}

BOOST_AUTO_TEST_SUITE_END()