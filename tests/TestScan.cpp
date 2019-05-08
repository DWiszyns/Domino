//
// Created by dominik on 4/11/19.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Source.h"
#include "Scanner.h"

/*class MockSource : public Source{
public:
    MOCK_METHOD4(error,void(std::string message, std::string atom,int atomLine, int atomPos));
    MOCK_METHOD4(error,void(std::string word, int atomLine, int atomPos, std::string errorLabel));
    MOCK_METHOD0(nextChar,void());

};*/
TEST(ScanTest,Opening_Source_Test){
    Source src("../../src/test1.tkom");
    Scanner scan(src);
    int c = scan.nextSymbol();
    EXPECT_EQ( c, 0 );

}
