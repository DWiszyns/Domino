//
// Created by dominik on 4/10/19.
//

#include "gtest/gtest.h"
#include "Source.h"

TEST(SourceTest,Opening_Source_Test){
    Source src("../../src/test1.tkom");
    EXPECT_EQ( src.isOpen(), true );
}

TEST(SourceTest,Getting_Char_Test){
    Source src("../../src/test1.tkom");
    char c=src.nextChar();
    EXPECT_EQ( c, 'f' );

}