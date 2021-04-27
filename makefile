exe: jeuDeLaVie.o main.o
	gcc jeuDeLaVie.o main.o -o exe

jeuDeLaVie.o: jeuDeLaVie.c jeuDeLaVie.h
	gcc -c jeuDeLaVie.c  -o jeuDeLaVie.o

main.o: main.c jeuDeLaVie.h
	gcc -c main.c -o main.o
