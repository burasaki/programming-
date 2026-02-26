# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes
set(SOURCES background.c)



add_library(BACKGROUND_LIB STATIC ${SOURCES})

target_link_libraries(BACKGROUND_LIB PIPE_LIB)