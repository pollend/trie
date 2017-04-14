cmake_minimum_required(VERSION 3.5)
project(trie)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c node.c tree.c   )
add_executable(trie ${SOURCE_FILES})