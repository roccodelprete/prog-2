cmake_minimum_required(VERSION 3.22)
project(elenco_studenti C)

set(CMAKE_C_STANDARD 11)

add_executable(elenco_studenti main.c lib.c lib.h)
