#[[
Здесь ваша реализация
]]

cmake_minimum_required(VERSION 3.10)
project(pr)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pipes
                    ${CMAKE_CURRENT_SOURCE_DIR}/background)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pipes)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/background)

add_executable(main ${SOURCE_DIR}/main.c)
target_link_libraries(main BACKGROUND_LIB)