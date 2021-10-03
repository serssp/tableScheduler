cmake_minimum_required(VERSION 3.20)
project(TS2 C)

set(CMAKE_C_STANDARD 99)

add_executable(TS2 main.c db.c db.h config.c algo.c algo.h)
