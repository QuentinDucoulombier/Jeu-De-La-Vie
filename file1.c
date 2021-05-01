#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "file1.h"


int** allouer(int lignes, int colonnes)
{
    int** matrice = malloc(lignes * sizeof(int*));

    for(int i = 0; i < colonnes; i++)
    {
        matrice[i] = malloc(colonnes * sizeof(int));
    }

    return matrice;
}

void initialiser(int** matrice, int lignes, int colonnes)
{
    int lire;
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            scanf("%d", &lire);
            matrice[i][j] = lire;
        }   
    }
}

void afficher(int** matrice, int lignes, int colonnes)
{
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            if(matrice[i][j] == 1)
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


void Libere (int** matrice, int lignes, int colonnes)
{
    for (int i = 0; i < lignes; i++)
    {
        free(matrice[i]);
    }
    free(matrice);
}

void vivreFermee(int** matrice, int** matrice2, int lignes, int colonnes)
{
    int temp;
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            temp = 0;
            if(matrice[i][j] == 1)
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][j] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;

                if(temp < 2 || temp > 3)
                    matrice2[i][j] == 0;
            }

            if(matrice[i][j] == 0)
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][j] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;

                if(temp == 3)
                    matrice2[i][j] == 1;
            }
        }
    }
}

void vivreTorique(int** matrice, int** matrice2, int lignes, int colonnes)
{
    int temp;
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            temp = 0;
            
            if(i == 0 && j != 0 && j != colonnes-1)
            {
                if(matrice[lignes-1][j-1] == 1)
                    temp++;
                if(matrice[lignes-1][j] == 1)
                    temp++;
                if(matrice[lignes-1][j+1] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;
            }
            else if(i == lignes-1 && (j != 0 && j != lignes-1))
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                        temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[0][j-1] == 1)
                    temp++;
                if(matrice[0][j] == 1)
                    temp++;
                if(matrice[0][j+1] == 1)
                    temp++;
            }
            else if(j == 0 && i != 0 && i != lignes-1)
            {
                temp =0;
                if(matrice[i-1][lignes-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][lignes-1] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][lignes-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;
            }
            else if(j == colonnes-1 && (i !=0 && i != lignes-1))
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][0] == 1)
                   temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][0] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][0] == 1)
                    temp++;
            }
            else if(i == 0 && j == 0)
            {
                if(matrice[lignes-1][colonnes-1] == 1)
                    temp++;
                if(matrice[lignes-1][j] == 1)
                    temp++;
                if(matrice[lignes-1][j+1] == 1)
                    temp++;
                if(matrice[i][colonnes-1] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][colonnes-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;
            }
            else if(i == lignes-1 && j == 0)
            {
                if(matrice[i-1][colonnes-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][colonnes-1] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[0][colonnes-1] == 1)
                    temp++;
                if(matrice[0][j] == 1)
                    temp++;
                if(matrice[0][j+1] == 1)
                    temp++;
            }
            else if(i == 0 && j == colonnes-1)
            {
                if(matrice[lignes-1][j-1] == 1)
                    temp++;
                if(matrice[lignes-1][j] == 1)
                    temp++;
                if(matrice[lignes-1][0] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][0] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][0] == 1)
                    temp++;
            }
            else if(i == lignes-1 && j == colonnes-1)
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][0] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][0] == 1)
                    temp++;
                if(matrice[0][j-1] == 1)
                    temp++;
                if(matrice[0][j] == 1)
                    temp++;
                if(matrice[0][0] == 1)
                    temp++;
            }

            if(temp == 0)
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][j] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;
            }
            
            if(matrice[i][j] == 1)
            {
                if(temp < 2 || temp > 3)
                    matrice2[i][j] = 0;
            }
            else
            {
                if(temp == 3)
                    matrice2[i][j] = 1;
            }
        }
    }
}

void copyTab(int** tab, int** tab2, int lignes, int colonnes)
{
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            tab[i][j] = tab2[i][j];
        }
    }
}
