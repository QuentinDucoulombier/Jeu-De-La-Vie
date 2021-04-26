exe: puissance4.o main.o
	gcc puissance4.o main.o -o exe

puissance4.o: puissance4.c puissance4.h
	gcc -c puissance4.c  -o puissance4.o

main.o: main.c puissance4.h
	gcc -c main.c -o main.o
