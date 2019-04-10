cmake_minimum_required(VERSION 3.13)
project(Domino)

set(CMAKE_CXX_STANDARD 17)

add_executable(Domino src/main.cpp src/Source.cpp src/Source.h src/Scan.cpp src/Scan.h src/ScanDef.h)

