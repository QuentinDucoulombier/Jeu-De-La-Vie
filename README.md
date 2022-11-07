# Jeu de la vie

## Présentation

Le [jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie) est un automate cellulaire conçu par le mathématicien britannique John Horton Conway en 1970. Il s'agit d'un jeu sans joueur, ce qui signifie que son évolution est déterminée par son état initial et ne nécessite aucune autre entrée. On interagit avec le jeu de la vie en créant une configuration initiale et en observant comment elle évolue. Il est turing complet.

Cette version en [c](https://fr.wikipedia.org/wiki/Jeu_de_la_vie) permet notamment de sortie du cadre prédéfinie (voir exemple 2) et elle compte également le nombre tours effectué.

Exemple de sortie:  
1. 
<img src="dataForReadme/clown.gif" alt="figure clown dans le jeu de la vie" width="800">
2. 
<img src="dataForReadme/spaceship.gif" alt="figure spaceship dans le jeu de la vie" width="800">


## Instalation 
Le programme "JEU DE LA VIE" doit être exécuté de la manière suivante:
- Entrer la commande git clone https://github.com/jeu-de-la-vie/Jeu-de-la-vie ou utiliser les fichiers du dossier de rendu.
- Ouvrir un terminal et se placer dans le dossier /Jeu-de-la-vie
- Executer les commandes suivant:
```bash
make //Pour compiler le programme
```
Puis,
```
cat Figure/nomDeLaFigure.txt | ./exe
```
avec nomDeLaFigure le nom d'une des figures présentes dans le dossier [/Figure](./Figure/)
Enfin vous pouvez entrer la commande
```
make clear
```
Lorsque vous avez fini d'utiliser le programme


