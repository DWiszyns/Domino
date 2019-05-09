//
// Created by dominik on 4/10/19.
//
#include <iostream>
#include "gtest/gtest.h"
#include "Source.h"



TEST(SourceTest,Example_Source_Test){
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
}
