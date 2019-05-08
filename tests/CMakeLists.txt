project(lexer_test)

include_directories(../lib/googletest-master/googletest/include)
include_directories(../lib/googletest-master/googlemock/include)
include_directories(../src)


add_executable(basictests TestSource.cpp TestScan.cpp TestParser.cpp)

target_link_libraries(basictests gtest gtest_main DominoLib)
