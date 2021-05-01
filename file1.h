#ifndef __FILE1__
#define __FILE1__

int** allouer(int lignes, int colonnes);
void initialiser(int** matrice, int lignes, int colonnes);
void afficher(int** matrice, int lignes, int colonnes);
void Libere (int** matrice, int lignes, int colonnes);
void vivreTorique(int** matrice, int** matrice2, int lignes, int colonnes);
void vivreFermee(int** matrice, int** matrice2, int lignes, int colonnes);
void copyTab(int** tab, int** tab2, int lignes, int colonnes);

#endif