cmake_minimum_required(VERSION 3.13)
project(lexer_test)

set(CMAKE_CXX_STANDARD 17)

include_directories(../lib/googletest-master/googletest/include)
include_directories(../lib/googletest-master/googlemock/include)
include_directories(../src)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(basictests TestSource.cpp TestScan.cpp TestParser.cpp testsMain.cpp TestRational.cpp)

#target_link_libraries(basictests gtest gtest_main gmock gmock_main DominoLib)
target_link_libraries(basictests ${Boost_LIBRARIES} DominoLib)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
