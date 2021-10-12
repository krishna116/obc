cmake_minimum_required(VERSION 3.15)

set(ANTLR4_INCLUDE_DIR "" CACHE STRING "set antlr4 include directory.")
set(ANTLR4_LIBRARY_DIR "" CACHE STRING "set antlr4 library directory.")
set(ANTLR4_LIBRARY_NAME "" CACHE STRING "set antlr4 library name.")

project(obc VERSION 0.1.0 LANGUAGES CXX)

configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h)

add_subdirectory(src)
