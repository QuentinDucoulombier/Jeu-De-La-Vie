#ifndef __FILE1__
#define __FILE1__

int** allouer(int lignes, int colonnes);
void initialiser(int** matrice, int lignes, int colonnes);
void afficher(int** matrice, int lignes, int colonnes);
void Libere (int** matrice, int lignes, int colonnes);
int voisinSansBord(int** matrice, int i, int j, int temp);
void vivreTorique(int** matrice, int** matrice2, int lignes, int colonnes);
void vivreFermee(int** matrice, int** matrice2, int lignes, int colonnes);
void copyMatrice(int** tab, int** tab2, int lignes, int colonnes);

#endif