//
// Created by dominik on 5/8/19.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Source.h"
#include "Scanner.h"
#include "Parser.h"

/*
class MockSource : public Source{
public:
    MockSource(std::string source): Source(source,true){};
    MOCK_METHOD4(error,void(std::string message, std::string atom,int atomLine, int atomPos));
    MOCK_METHOD4(error,void(std::string word, int atomLine, int atomPos, std::string errorLabel));
    MOCK_METHOD0(nextChar,char());

};

class MockScanner : public Scanner{
public:
    MockScanner(MockSource &source): Scanner(source){};
    MOCK_METHOD2(scanError,void(int ec, std::string atom));
    MOCK_METHOD2(scanError,void(SymbolType atom, std::string word));
    MOCK_METHOD0(nextSymbol,SymbolType());

};


TEST(ParserTest,Example_Parse_Test){
    MockSource src("function xyz():void{} function main():void{}");
    MockScanner scan(src);
    EXPECT_CALL(scan,nextToken())
    .Times(testing::AtLeast(1))
    .WillOnce(testing::Return(FUNCSY));
    Parser parser(scan);
}
 */


