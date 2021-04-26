#ifndef _jeuDeLaVie_H_
#define _jeuDeLaVie_H_

//void afficher(int tab, int largeur, int longueur);
int** Allouer(int largeur, int longueur);
void Initialisation(int** tab, int largeur, int longueur);
void afficher(int** tab, int largeur, int longueur);
void Libere (int** tab, int largeur, int longueur);

#endif
