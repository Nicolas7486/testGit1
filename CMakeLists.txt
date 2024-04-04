cmake_minimum_required(VERSION 3.13)
project(ing1_2023_2024_groupe13_equipe2 C)


set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-L/usr/local/lib -lalleg -lm")
add_executable(ing1_2023_2024_groupe13_equipe2 main.c
        Sous-Programme.h
        Sous-Programme.c
        items.c)
