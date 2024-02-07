cmake_minimum_required(VERSION 3.27)
project(CCodeSnippets C)

set(CMAKE_C_STANDARD 23)

add_executable(CCodeSnippets main.c
        Filehandling/writeInFile.c
        Filehandling/writeInFile.h
        Filehandling/readFromFile.c
        Filehandling/readFromFile.h)
