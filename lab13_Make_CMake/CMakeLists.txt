cmake_minimum_required(VERSION 3.10)

project(prog)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCES
    ${SOURCE_DIR}/func.c
)


option(IS_SHARED_LIB "Тип используемой библиотеки" NO)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(IS_SHARED_LIB)
    add_library(UTIL_LIB SHARED ${SOURCES})
else()
    add_library(UTIL_LIB STATIC ${SOURCES})
endif()

add_executable(main ${SOURCE_DIR}/main.c)
target_link_libraries(main UTIL_LIB)