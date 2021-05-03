#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "file1.h"

int main()
{
    int lire = 0;
    scanf("%d", &lire);
    int lignes = lire + 2;
    scanf("%d", &lire);
    int colonnes = lire + 2;

    int** matrice1 = allouer(lignes, colonnes);
    int** matrice2 = allouer(lignes, colonnes);

    initialiser(matrice1, lignes, colonnes);

    scanf("%d", &lire);
    int nombreDeTours = lire;
    scanf("%d", &lire);
    int torique = lire;

    printf("\n\nLe jeu va commencer dans 1 seconde !\n");
    sleep(1);

    if(torique == 0)
    {
        while(1)
        {
            copyMatrice(matrice2, matrice1, lignes, colonnes);
            usleep(300000);
            printf("\033[2J");
            printf("\033[H");
            afficher(matrice1, lignes, colonnes);
            vivreFermee(matrice2, matrice1, lignes, colonnes);
        }
    }else{
        while(nombreDeTours)
        {
            printf("\033[2J");
            printf("\033[H");
            afficher(matrice1, lignes, colonnes);
            copyMatrice(matrice2, matrice1, lignes, colonnes);
            vivreTorique(matrice2, matrice1, lignes, colonnes);
            usleep(100000);
        }
    }

    Libere (matrice1, lignes, colonnes);
    Libere (matrice2, lignes, colonnes);

    return 0;
}