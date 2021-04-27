//Jeu de la Vie
//Commencé le 17/04/2021
//Fait par Omar BENZEROUAL
//En classe de Pré Ingé 1


#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "jeuDeLaVie.h"


int** Allouer(int largeur, int longueur)
{
    int** tab;
    tab = malloc(largeur *sizeof(int*));
    for (int i = 0; i < largeur; i++)
    {
        tab[i]= malloc(longueur * sizeof(int));
    }
    return tab;

}




void Initialisation(int** tab, int largeur, int longueur)
{
    for (int i = 0; i < largeur; i++)
    {
        for (int j = 0; j < longueur; j++)
        {
            tab[i][j] = 0;
        }
        
    }

}


void Libere (int** tab, int largeur, int longueur)
{

    for (int i = 0; i < largeur; i++)
    {
        free(tab[i]);
        
    }
    free(tab);
}



void afficher(int** tab, int largeur, int longueur)
{
    for(int i = 0; i < largeur; i++)
    {
        for(int j = 0; j < longueur; j++)
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
        printf("\n");
    }
}

void vivreEtMourir(int** tab, int** tab2, int largeur, int longueur)
{
    for(int i = 1; i < largeur-1; i++)
    {
        for(int j = 1; j < longueur-1; j++)
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


void copyTab(int** tab, int** tab2, int largeur, int longueur)
{
    for(int i = 0; i < largeur; i++)
    {
        for(int j = 0; j < longueur; j++)
        {
            tab[i][j] = tab2[i][j];
        }
    }
}



