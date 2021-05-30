/*!
    \file fonction.h
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \brief fichier d'en-têtes pour fonction.c
    \remarks Aucune

    Prototypage des fonctions et procédures.

*/


#ifndef _FONCTION_H_
#define _FONCTION_H_

/* Prototypes de fonctions */

/*!
    \fn int** allouer(int lignes, int colonnes);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param lignes le nombre de lignes rentrées dans le .txt de la figure
    \param colonnes le nombre de colonnes rentrées dans le .txt de la figure
    \return un tableau de pointeur 2D d'entier de la taille de lignes * colonnes
    \brief permet de cree le tableau de jeu
    \remarks Aucune
*/
int** allouer(int lignes, int colonnes);

/*!
    \fn void initialiser(int** matrice, int lignes, int colonnes);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param matrice le tableau dynamique cree par la fonction precedente
    \param lignes le nombre de lignes rentrées dans le .txt de la figure
    \param colonnes le nombre de colonnes rentrées dans le .txt de la figure
    \brief initialise le tableau cree precedemment avec les 1 et les 0 present dans le .txt de la figure
    \remarks Aucune
*/
void initialiser(int** matrice, int lignes, int colonnes);

/*!
    \fn void afficher(int** matrice, int lignes, int colonnes);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param matrice le tableau dynamique cree par la fonction allouer et initialiser par la procedure du meme nom
    \param lignes le nombre de lignes rentrées dans le .txt de la figure
    \param colonnes le nombre de colonnes rentrées dans le .txt de la figure
    \brief affiche le tableau cree et initialisé precedemment avec des carrés de couleurs
    \remarks Aucune
*/
void afficher(int** matrice, int lignes, int colonnes);

/*!
    \fn void Libere (int** matrice, int lignes);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param matrice le tableau dynamique cree par la fonction allouer et initialiser par la procedure du meme nom
    \param lignes le nombre de lignes rentrées dans le .txt de la figure
    \brief libere le tableau
    \remarks Aucune
*/
void Libere (int** matrice, int lignes);

/*!
    \fn int voisinSansBord(int** matrice, int i, int j, int temp);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param matrice le tableau dynamique cree par la fonction allouer et initialiser par la procedure du meme nom
    \param i variable de la premiere boucle qui va de 1 a ligne-1 dans la fonction vivreFermee
    \param j variable de la seconde boucle qui va de 1 a colonne-1 dans la fonction vivreFermee
    \param temp compte le nombre de cellules vivante autour de i et de j
    \return le nombre de cellules vivante autour de i et j
    \brief permet de compter le nombre de cellule autour de i et j
    \remarks Aucune
*/
int voisinSansBord(int** matrice, int i, int j, int temp);

/*!
    \fn void vivreFermee(int** matrice, int** matrice2, int lignes, int colonnes);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param matrice le tableau dynamique cree par la fonction allouer et initialiser par la procedure du meme nom
    \param matrice2 un tableau temporaire qui permet de modifier la matrice (qui est ensuite copier dans la fonction copytab) 
    \param lignes le nombre de lignes rentrées dans le .txt de la figure
    \param colonnes le nombre de colonnes rentrées dans le .txt de la figure
    \brief permet de modifier l'etat des cellules selon le nombre de celulles vivante/morte dans le cas d'une matrice fermé
    \remarks Aucune
*/
void vivreFermee(int** matrice, int** matrice2, int lignes, int colonnes);

/*!
    \fn void vivreTorique(int** matrice, int** matrice2, int lignes, int colonnes);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param matrice le tableau dynamique cree par la fonction allouer et initialiser par la procedure du meme nom
    \param matrice2 un tableau temporaire qui permet de modifier la matrice (qui est ensuite copier dans la fonction copytab) 
    \param lignes le nombre de lignes rentrées dans le .txt de la figure
    \param colonnes le nombre de colonnes rentrées dans le .txt de la figure
    \brief permet de compter et de modifier l'etat des cellules selon le nombre de celulles vivante/morte dans le cas d'une matrice torique
    \remarks Aucune
*/
void vivreTorique(int** matrice, int** matrice2, int lignes, int colonnes);

/*!
    \fn void vivreTorique(int** matrice, int** matrice2, int lignes, int colonnes);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \author Omar Benzeroual
    \date 24/04/2021
    \param matrice le tableau dynamique cree par la fonction allouer et initialiser par la procedure du meme nom
    \param matrice2 un tableau temporaire qui permet de modifier la matrice (qui est ensuite copier dans la fonction copytab) 
    \param lignes le nombre de lignes rentrées dans le .txt de la figure
    \param colonnes le nombre de colonnes rentrées dans le .txt de la figure
    \brief permet de copier les deux matrice2 dans la matrice 1
    \remarks Aucune
*/
void copyMatrice(int** matrice, int** matrice2, int lignes, int colonnes);

#endif