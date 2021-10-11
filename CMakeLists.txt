cmake_minimum_required(VERSION 3.15)

project(obc VERSION 0.1.0 LANGUAGES CXX)

configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h)

# This variable may need update.
set(ANTLR4_INCLUDE_PATH E:/msys64/mingw64/include/antlr4-runtime cache INTERNAL "")

add_subdirectory(src)
