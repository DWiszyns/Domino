//
// Created by dominik on 4/10/19.
//

#include "gtest/gtest.h"
#include "Source.h"

TEST(test1,test1_tes_Test){
    Source src("../src/test1.tkom");
    EXPECT_EQ( src.isOpen(), true );
}