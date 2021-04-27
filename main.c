#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "jeuDeLaVie.h"




int main()
{
    int largeur = 20;
    int longueur = 60;

    int **tabJeu = NULL;
    int **tabTemp = NULL;

    tabJeu = Allouer(largeur, longueur);
    tabTemp = Allouer(largeur, longueur);

    Initialisation(tabJeu, largeur, longueur);
    Initialisation(tabTemp, largeur, longueur);

    tabJeu[15][4] = 1;
    tabJeu[14][5] = 1;
    tabJeu[14][6] = 1;
    tabJeu[15][6] = 1;
    tabJeu[16][6] = 1;

    

    printf("Le jeu va commencer !! \nAppuyez sur ctrl+C pour arrêter le jeu. \n\n\nC'EST PARTI !");
    sleep(1);

    while (1)
    {
        copyTab(tabTemp, tabJeu, largeur, longueur);
        sleep(1);
        printf("\033[2J");
        printf("\033[H");
        afficher(tabJeu, largeur, longueur);
        vivreEtMourir(tabTemp, tabJeu, largeur, longueur);
    }
    
    
    Libere(tabJeu, largeur, longueur);

    return 0;
}
