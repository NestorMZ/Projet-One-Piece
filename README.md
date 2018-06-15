# Projet-One-Piece

## Principe du jeu 
Le jeu DUMBAL se joue entre 2 et 4 joueurs. Chaque joueur commence avec 100 points de vie. On distribue 7 cartes à chaque joueur. Les joueurs jouent tour à tour, ils ont le choix de déposer une carte, un double de deux cartes de même valeur, un triple, un quadruple ou bien une suite de cartes rouges ou noires (4 cartes minimum). Suite à ça, le joueur peut piocher ou récupérer la dernière carte déposée (ou une des dernières cartes si plusieurs).
Chaque carte vaut en nombre de points la valeur indiquée par son chiffre : As = 1 point, 7 = 7 points, Valet Dame ou Roi = 10 points.

> __Pour gagner__: l'objectif est de réussir à avoir dans sa main 11 points ou moins. Quand c'est le cas et seulement si le joueur n'a pas encore joué (c'est à son tour de jouer), le joueur peut alors dire `DUMBAL`. 

Lorsque qu'un `DUMBAL` est déclenché, le joueur à l'origine révèle son jeu et son nombre de points au reste des joueurs qui révèlent eux aussi leur jeu. Si un autre joueur a un nombre de points inférieur au joueur qui a déclenché le `DUMBAL`, alors on appelle cette situation un `CONTRE DUMBAL` et le joueur à l'origine perd 35 points de vie + le nombre de points de sa main.
Sinon, tous les autres joueurs perdent en points de vie le nombre de points qu'ils ont en main.
Quand un joueur n'a plus de point de vie, il est éliminé.

### Choix des structures de données
Pour mettre en place notre jeu de cartes nous avons décidé de créer plusieurs classes et d'en utiliser d'autres déjà existantes.

#### Les Cartes
Pour ce qui est de nos cartes nous allons créer une classe `Carte` qui sera de la forme : 
~~~
Carte {
          int valeur;
          int famille;
          
          //Puis les methodes
          }
~~~
On a choisi d'utiliser deux entiers car les entiers sont simples à manipuler. Une valeur de 11 correspondra à un Valet, 12 à une Dame et 13 à un Roi. Pour l'entier famille, on organisera de la manière suivante : 
~~~
0 = Coeur
1 = Pique
2 = Carreau
3 = Trèfle
~~~
On utilisera par la suite des pointeurs vers nos cartes pour optimiser la mémoire au maximum.

#### La Pioche et le Tas
Pour la pioche et pour le tas nous avons besoin de mélanger et de connaître la carte la plus haute.
On utilisera si il existe le type `Stack` auquel on ajoutera un entier contenant le nombre de cartes de la pioche.
On créera une structure `Noeud`:
~~~
Noeud {
          Carte* carte;
          Carte* suivante;
          }
~~~ 

#### Le Joueur
Nos joueurs seront représenter par une classe contenant des methodes et une liste chaînée de cartes.

Idées pour les méthodes : quoi jouer, dumbal, piocher tas/pioche, ordonner (Bonus).

## VERSION 1.0

Cette version sera codée en C++ et jouable via le terminal.
~~~
4 joueurs maximum.
S'effectuera dans l'odre :
- Combien de joueurs ?
- Pseudos
- Tour par Tour : quelles cartes jouer, on les stocke dans un tableau, on vérifie...
- Dumbal
- Fin de partie quand un seul joueur restant.
~~~

### Bonus et améliorations à venir
-Interface graphique
-Intelligence artificielle (IA)
-Ajout des jockers
-Réseau
-Application mobile
