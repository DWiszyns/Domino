//
// Created by dominik on 4/11/19.
//

#include "gtest/gtest.h"
#include "Source.h"
#include "Scan.h"

TEST(ScanTest,Opening_Source_Test){
    Source src("../../src/test1.tkom");
    Scan scan(src);
    int c = scan.nextSymbol();
    EXPECT_EQ( c, 0 );

}
