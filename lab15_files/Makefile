all: main.exe

main.exe: main.o func.o
	gcc main.o func.o -o main.exe

main.o: ./main.c func.o
	gcc main.c -c

func.o: ./func.c
	gcc func.c -c

run: main.exe
	./main.exe
clear:
	rm *.o *.dat *.compressed *.exe decompressed* 2>/dev/null