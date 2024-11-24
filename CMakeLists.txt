cmake_minimum_required(VERSION 3.28)
project(MergePlusInsertionSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(MergePlusInsertionSort
        ArrayGenerator.h
        ArrayGenerator.cpp
        SortTester.h
        SortTester.cpp
        MergeInsertionSort.cpp
        MergeInsertionSort.cpp)
