//
// Created by dominik on 5/8/19.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Source.h"
#include "Scanner.h"
#include "Parser.h"

using ::testing::_;

class MockSource : public Source{
public:
    MockSource(std::string source): Source(source,true){};
    MOCK_METHOD4(error,void(std::string message, std::string atom,int atomLine, int atomPos));
    MOCK_METHOD4(error,void(std::string word, int atomLine, int atomPos, std::string errorLabel));
    MOCK_METHOD0(nextChar,void());

};

class MockScanner : public Scanner{
public:
    MockScanner(MockSource &source): Scanner(source){};
    MOCK_METHOD2(scanError,void(int ec, std::string atom));
    MOCK_METHOD2(scanError,void(SymbolType atom, std::string word));
    MOCK_METHOD0(nextSymbol,void());

};


TEST(ParserTest,Empty_Source_Test){
    MockSource src(" ");
    MockScanner scan(src);
    EXPECT_CALL(scan,nextSymbol());
    Parser parser(scan);
    parser.program();
}

