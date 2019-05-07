cmake_minimum_required(VERSION 3.13)
project(Domino)

file(GLOB_RECURSE Headers *.h)
file(GLOB_RECURSE Sources *cpp)

add_executable(Domino main.cpp Source.cpp Source.h Scanner.cpp Scanner.h ScanDef.h Parser.cpp Parser.h)
add_library(DominoLib STATIC ${Headers} ${Sources})