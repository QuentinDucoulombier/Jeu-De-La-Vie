exe: fonction.o main.o
	gcc -Wall fonction.o main.o -o exe

fonction.o: fonction.c fonction.h
	gcc -c fonction.c  -o fonction.o

main.o: main.c fonction.h
	gcc -c main.c -o main.o

clear: exe
	rm -f *.o
	@echo "tout a été éffacé"
