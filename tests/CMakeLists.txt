cmake_minimum_required(VERSION 3.10)
project(interpreter_test)

set(CMAKE_CXX_STANDARD 17)

include_directories(../src)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(basictests TestSource.cpp TestScan.cpp TestParser.cpp testsMain.cpp TestRational.cpp ast/Expressions/TestExpressions.cpp ast/Expressions/TestSimpleExpression.cpp ast/Expressions/TestValueFactor.cpp ast/Expressions/TestExpressionFactor.cpp ast/TestNode.cpp ast/TestVariable.cpp ast/Statements/TestAssignment.cpp ast/TestParametersDefinition.cpp)

#target_link_libraries(basictests gtest gtest_main gmock gmock_main DominoLib)
target_link_libraries(basictests ${Boost_LIBRARIES} DominoLib)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
