cmake_minimum_required(VERSION 3.21)
project(NewFamilyTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(NewFamilyTree main.cpp NewFamilyTree_lib/Person.h NewFamilyTree_lib/Person.cpp )
add_subdirectory(NewFamilyTree_lib)
