//
// Created by dominik on 4/11/19.
//

#include "gtest/gtest.h"
#include "Source.h"
#include "Scanner.h"

TEST(ScanTest,Opening_Source_Test){
    Source src("../../src/test1.tkom");
    Scanner scan(src);
    int c = scan.nextSymbol();
    EXPECT_EQ( c, 0 );

}
