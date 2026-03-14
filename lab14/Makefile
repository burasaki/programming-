all: main.exe

main.exe: main.o libfunc.a
	gcc main.o -o main.exe -L. -lfunc

libfunc.a: func.o
	ar rc libfunc.a func.o


main.o: ./main.c func.o
	gcc main.c -c

func.o: ./func.c
	gcc func.c -c

run: main.exe
	./main.exe