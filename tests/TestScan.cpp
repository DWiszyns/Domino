//
// Created by dominik on 4/11/19.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Source.h"
#include "Scanner.h"

/*
class MockSource : public Source{
public:
    MockSource(std::string source): Source(source,true){};
    MOCK_METHOD4(error,void(std::string message, std::string atom,int atomLine, int atomPos));
    MOCK_METHOD4(error,void(std::string word, int atomLine, int atomPos, std::string errorLabel));
    MOCK_METHOD0(nextChar,char());

};
TEST(ScanTest,Opening_Source_Test){
    MockSource src("function x():void{} function main():void{}");
    Scanner scan(src);
    int c = scan.nextSymbol();
    EXPECT_EQ( FUNCSY, c );

}

TEST(ScanTest,Function_Call_Test){
    MockSource src("function x():void{} function main():void{}");
    Scanner scan(src);
    EXPECT_CALL(src,nextChar())
    .Times(testing::AtLeast(1))
    .WillOnce(testing::Return('f'));
    int c = scan.nextSymbol();
}


TEST(ScanTest,Error_Call_Test){
    MockSource src("function x():void{} function main():void{}");
    Scanner scan(src);
    EXPECT_CALL(src,error("wrong", "function",1, 0))
            .Times(testing::AtLeast(1));
    scan.scanError(FUNCSY,"wrong");
}
*/