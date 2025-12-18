all: main

main: main.o func.o
	gcc main.o func.o -o main.exe -o main.exe

main.o: main.c
	gcc main.c -c

func.o: func.c
	gcc func.c -c 

clean:
	rm -r *.o main.exe