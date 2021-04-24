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
#include "jeuDeLaVie.h"


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

void vivreEtMourir(int tab[LARGEUR][LONGUEUR], int tab2[LARGEUR][LONGUEUR])
{
    for(int i = 1; i < LARGEUR-1; i++)
    {
        for(int j = 1; j < LONGUEUR-1; j++)
        {
            int temp = 0;
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



