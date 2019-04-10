cmake_minimum_required(VERSION 3.13)
project(Domino)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest-master)
add_subdirectory(tests)
add_subdirectory(src)

#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)
#include_directories(src)

#add_executable(Domino src/main.cpp src/Source.cpp src/Source.h src/Scan.cpp src/Scan.h src/ScanDef.h)
#add_library(ElkaRoyaleLib STATIC ${Headers} ${Sources})

