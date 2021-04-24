//Jeu de la Vie
//Commencé le 17/04/2021
//Fait par Omar BENZEROUAL
//En classe de Pré Ingé 1

#define LARGEUR 20
#define LONGUEUR 60
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void afficher(int tab[LARGEUR][LONGUEUR])
{
    for(int i = 0; i < LARGEUR; i++)
    {
        for(int j = 0; j < LONGUEUR; j++)
        {
            if(j == LONGUEUR-1)
            {
                if(tab[i][j] == 1)
                {
                    printf("\033[0;34m");
                    printf("•\n");
                }
                else
                {
                    printf("\033[0;31m");
                    printf("•\n");
                } 
            }
            else
            {
                if(tab[i][j] == 1)
                {
                    printf("\033[0;34m");
                    printf("•");
                }
                else
                {
                    printf("\033[0;31m");
                    printf("•");
                }
            }
        }
    }
}

void vivreEtMourir(int tab[LARGEUR][LONGUEUR], int tab2[LARGEUR][LONGUEUR], int temp)
{
    for(int i = 1; i < LARGEUR-1; i++)
    {
        for(int j = 1; j < LONGUEUR-1; j++)
        {
            temp = 0; //pk on importe temp si on le met a 0 directement dans la fonction

            if(tab[i][j] == TRUE)
            
            {
                if(tab[i-1][j-1] == TRUE)
                    temp++;
                if(tab[i-1][j] == TRUE)
                    temp++;
                if(tab[i-1][j+1] == TRUE)
                    temp++;
                if(tab[i][j-1] == TRUE)
                    temp++;
                if(tab[i][j+1] == TRUE)
                    temp++;
                if(tab[i+1][j-1] == TRUE)
                    temp++;
                if(tab[i+1][j] == TRUE)
                    temp++;
                if(tab[i+1][j+1] == TRUE)
                    temp++;

                if(temp < 2 || temp > 3) //meurt de sous/sur population
                    tab2[i][j] = FALSE;
            }

            if(tab[i][j] == FALSE)
            {
                if(tab[i-1][j-1] == TRUE)
                    temp++;
                if(tab[i-1][j] == TRUE)
                    temp++;
                if(tab[i-1][j+1] == TRUE)
                    temp++;
                if(tab[i][j-1] == TRUE)
                    temp++;
                if(tab[i][j+1] == TRUE)
                    temp++;
                if(tab[i+1][j-1] == TRUE)
                    temp++;
                if(tab[i+1][j] == TRUE)
                    temp++;
                if(tab[i+1][j+1] == TRUE)
                    temp++;
                
                if(temp == 3)   //creation d'une nvlle cellule
                    tab2[i][j] = TRUE;
            }
        }
    }
}


void copyTab(int tab[LARGEUR][LONGUEUR], int tab2[LARGEUR][LONGUEUR])
{
    for(int i = 0; i < LARGEUR; i++)
    {
        for(int j = 0; j < LONGUEUR; j++)
        {
            tab[i][j] = tab2[i][j];
        }
    }
}



int main()
{
    int tabJeu[LARGEUR][LONGUEUR] = {0};
    int tabTemp[LARGEUR][LONGUEUR] = {0};
    tabJeu[15][4] = 1;
    tabJeu[14][5] = 1;
    tabJeu[14][6] = 1;
    tabJeu[15][6] = 1;
    tabJeu[16][6] = 1;

    int temp = 0;

    printf("Le jeu va commencer !! \nAppuyez sur ctrl+C pour arrêter le jeu. \n\n\nC'EST PARTI !");
    sleep(3);

    while(1)
    {
        copyTab(tabTemp, tabJeu);
        sleep(1);
        printf("\033[2J");
        printf("\033[H");
        afficher(tabJeu);
        vivreEtMourir(tabTemp, tabJeu, temp);
    }


    return 0;
}