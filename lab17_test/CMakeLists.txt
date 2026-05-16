cmake_minimum_required(VERSION 3.10)
project(lab17_math C)

set(CMAKE_C_STANDARD 99)

add_library(main STATIC main.c)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(main m)

enable_testing()
add_subdirectory(test)
