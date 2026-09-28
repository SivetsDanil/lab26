cmake_minimum_required(VERSION 4.0)
project(lab26 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab26 sort.c
        udt.h
        udt.c)
