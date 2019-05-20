//
// Created by dominik on 4/10/19.
//

#define BOOST_TEST_MODULE source_test
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <iostream>
#include "gtest/gtest.h"
#include "Source.h"
#include <boost/test/unit_test.hpp>



/*TEST(SourceTest,Example_Source_Test){
    //Source src("function",true);
    Source src("function x():void{} function main():void{}",true);
    char c=src.nextChar();
    std::cout<<c;
    EXPECT_EQ( c, 'f' );
}

TEST(SourceTest,Error_Test){
    //Source src("function",true);
    Source src("function x():void{} function main():void{}",true);
    src.error("example","some atom",1,2);
    EXPECT_EQ( src.getErrorTotal(), 1 );
}

TEST(SourceTest,Error2_Test){
    //Source src("function",true);
    Source src("function x():void{} function main():void{}",true);
    src.error("example",1,2,"some atom");
    EXPECT_EQ( src.getErrorTotal(), 1 );
}*/

BOOST_AUTO_TEST_SUITE(SourceTest)

BOOST_AUTO_TEST_CASE(check_next_char){
        Source src("function x():void{} function main():void{}",true);
        char c=src.nextChar();
        BOOST_CHECK_EQUAL( c, 'f' );
}

BOOST_AUTO_TEST_SUITE_END()