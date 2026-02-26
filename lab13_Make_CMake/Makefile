TARGET = main.exe
CC = gcc
INCLUDE_DIR = ./include

all: $(TARGET)

main.exe: main.o libfunc.a
	${CC} main.o -o main.exe -L. -lfunc

libfunc.a: func.o
	ar rc libfunc.a func.o


main.o: src/main.c func.o
	${CC} src/main.c -c -I ${INCLUDE_DIR}

func.o: src/func.c
	${CC} src/func.c -c -I ${INCLUDE_DIR}

run: $(TARGET)
	./$(TARGET)

clear:
	rm *.a *.o *.exe