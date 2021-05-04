#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "file1.h"



int** allouer(int lignes, int colonnes)
{
    int** matrice = NULL;
    matrice = malloc(lignes * sizeof(int*));

    for(int i = 0; i < lignes; i++)
    {
        matrice[i] = malloc(colonnes * sizeof(int));
    }
    return matrice;
}

void initialiser(int** matrice, int lignes, int colonnes)
{
    int lire;
    for(int i = 0; i < lignes - 2; i++)
    {
        for(int j = 0; j < colonnes - 2; j++)
        {
            scanf("%d", &lire);
            matrice[i + 1][j + 1] = lire;
        }   
    }
}

void afficher(int** matrice, int lignes, int colonnes)
{
    for(int i = 1; i < lignes - 1; i++)
    {
        for(int j = 1; j < colonnes - 1; j++)
        {
            if(matrice[i][j] == 1)
            {
                printf("\033[0;34m");
                printf(" ■");
            }
            else
            {
                printf("\033[0;31m");
                printf(" ■");
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
    for(int i = 1; i < lignes - 1; i++)
    {
        for(int j = 1; j < colonnes - 1; j++)
        {
            int temp = 0;
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
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;

                if(temp < 2 || temp > 3) 
                    matrice2[i][j] = 0;
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
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;
                
                if(temp == 3)   
                    matrice2[i][j] = 1;
            }
        }
    }
}

void vivreTorique(int** matrice, int** matrice2, int lignes, int colonnes)
{
    int temp;
    for(int i = 1; i < lignes-1; i++)
    {
        for(int j = 1; j < colonnes-1; j++)
        {
            temp = 0;
            
            if(i == 1 && (j != 1 && j != colonnes-2)) //
            {
                if(matrice[lignes-2][j-1] == 1)
                    temp++;
                if(matrice[lignes-2][j] == 1)
                    temp++;
                if(matrice[lignes-2][j+1] == 1)
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
            else if(i == lignes-2 && (j != 1 && j != colonnes-2))
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
                if(matrice[1][j-1] == 1)
                    temp++;
                if(matrice[1][j] == 1)
                    temp++;
                if(matrice[1][j+1] == 1)
                    temp++;
            }
            else if(j == 1 && (i != 1 && i != lignes-2))
            {
                if(matrice[i-1][colonnes-2] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][colonnes-2] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][colonnes-2] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;
            }
            else if(j == colonnes-2 && (i != 1 && i != lignes-2))
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][1] == 1)
                   temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][1] == 1)
                    temp++;
            }
            else if(i == 1 && j == 1)
            {
                if(matrice[lignes-2][colonnes-2] == 1)
                    temp++;
                if(matrice[lignes-2][j] == 1)
                    temp++;
                if(matrice[lignes-2][j+1] == 1)
                    temp++;
                if(matrice[i][colonnes-2] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[i+1][colonnes-2] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][j+1] == 1)
                    temp++;
            }        
            else if(i == lignes-2 && j == 1)
            {
                if(matrice[i-1][colonnes-2] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][j+1] == 1)
                    temp++;
                if(matrice[i][colonnes-2] == 1)
                    temp++;
                if(matrice[i][j+1] == 1)
                    temp++;
                if(matrice[1][colonnes-2] == 1)
                    temp++;
                if(matrice[1][j] == 1)
                    temp++;
                if(matrice[1][j+1] == 1)
                    temp++;
            }
            else if(i == 1 && j == colonnes-2)
            {
                if(matrice[lignes-2][j-1] == 1)
                    temp++;
                if(matrice[lignes-2][j] == 1)
                    temp++;
                if(matrice[lignes-2][1] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][1] == 1)
                    temp++;
                if(matrice[i+1][j-1] == 1)
                    temp++;
                if(matrice[i+1][j] == 1)
                    temp++;
                if(matrice[i+1][1] == 1)
                    temp++;
            }
            else if(i == lignes-2 && j == colonnes-2)
            {
                if(matrice[i-1][j-1] == 1)
                    temp++;
                if(matrice[i-1][j] == 1)
                    temp++;
                if(matrice[i-1][1] == 1)
                    temp++;
                if(matrice[i][j-1] == 1)
                    temp++;
                if(matrice[i][1] == 1)
                    temp++;
                if(matrice[1][j-1] == 1)
                    temp++;
                if(matrice[1][j] == 1)
                    temp++;
                if(matrice[1][1] == 1)
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

void copyMatrice(int** matrice, int** matrice2, int lignes, int colonnes)
{
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            matrice[i][j] = matrice2[i][j];
        }
    }
}
