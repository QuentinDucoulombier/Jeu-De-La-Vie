exe: file1.o main.o
	gcc -Wall file1.o main.o -o exe

jeuDeLaVie.o: file1.c file1.h
	gcc -c file1.c  -o file1.o

main.o: main.c file1.h
	gcc -c main.c -o main.o

clear: exe
	rm -f *.o
	@echo "tout a été éffacé"
