int main()
{
    int tabJeu[LARGEUR][LONGUEUR] = {0};
    int tabTemp[LARGEUR][LONGUEUR] = {0};
    tabJeu[15][4] = 1;
    tabJeu[14][5] = 1;
    tabJeu[14][6] = 1;
    tabJeu[15][6] = 1;
    tabJeu[16][6] = 1;

    

    printf("Le jeu va commencer !! \nAppuyez sur ctrl+C pour arrêter le jeu. \n\n\nC'EST PARTI !");
    sleep(3);

    while(1)
    {
        copyTab(tabTemp, tabJeu);
        sleep(1);
        printf("\033[2J");
        printf("\033[H");
        afficher(tabJeu);
        vivreEtMourir(tabTemp, tabJeu);
    }


    return 0;
}