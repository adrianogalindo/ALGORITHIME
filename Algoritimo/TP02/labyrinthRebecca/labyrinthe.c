//*******************************************************************
// labyrinthe.c
// Rébecca
// 5 décembre 2018
// Résoud un labyrinthe selon l'algorithme de retour sur trace.
//*******************************************************************
#include <stdlib.h>
#include <stdio.h>

#define TAILLE 5
#define DESSIN_MUR "███"
#define DESSIN_SOURIS " · "
#define DESSIN_VIDE "   "

enum {VIDE, MUR, SOURIS};

//*******************************************************************
// void printLabyrinthe(int labyrinthe[TAILLE][TAILLE])
// Imprime le labyrinthe à la console
//
// INPUT :
//    labyrinthe : Un labyrinthe carré de dimension TAILLE
//        constitué de murs, de chemin parcouru et de cases libres.
//*******************************************************************
void printLabyrinthe(int labyrinthe[TAILLE][TAILLE])
{
  for (int i = 0; i < TAILLE + 2; i++)
    printf("%s", DESSIN_MUR);
  printf("\n");
  for (int i = 0; i < TAILLE; i++)
  {
    printf("%s", (i == 0 ? DESSIN_SOURIS: DESSIN_MUR));
    for (int j = 0; j < TAILLE; j++)
      switch (labyrinthe[i][j])
    	{
    	case MUR : printf("%s", DESSIN_MUR); break;
    	case VIDE : printf("%s", DESSIN_VIDE); break;
    	case SOURIS : printf("%s", DESSIN_SOURIS); break;
    	}
    printf("%s\n", (i == TAILLE - 1 ? DESSIN_SOURIS: DESSIN_MUR));
  }
  for (int i = 0; i < TAILLE + 2; i++)
    printf("%s", DESSIN_MUR);
  printf("\n\n");
}

//*************************************************************************************
// int longueurChemin(int labyrinthe[][TAILLE])
// Détermine la longueur du chemin parcouru par la souris dans le labyrinthe
//
// INPUT :
//    labyrinthe : Le labyrinthe, contenant les déplacements de la souris
// OUTPUT :
//    La longueur du chemin parcouru par la souris dans le labyrinthe
//*************************************************************************************
int longueurChemin(int labyrinthe[][TAILLE])
{
  int l = 0;
  for (int i = 0; i < TAILLE; i++)
    for (int j = 0; j < TAILLE; j++)
      l += labyrinthe[i][j] == SOURIS;
  return l;
}

//*************************************************************************************
// void copier(int dest[][TAILLE], int src[][TAILLE])
// Copie src dans dest
//
// INPUT :
//    dest : La matrice de destination
//    src : La matrice de source
//*************************************************************************************
void copier(int dest[][TAILLE], int src[][TAILLE])
{
  for (int i = 0; i < TAILLE; i++)
    for (int j = 0; j < TAILLE; j++)
      dest[i][j] = src[i][j];
}
//*************************************************************************************
// void trouverSorties(int labyrinthe[][TAILLE], int solution[][TAILLE], int x, int y)
// Trouve tous les chemins possible pour se rendre à la sortie à partir du point (x,y)
// dans le labyrinthe et met le plus court dans solution.
//
// INPUT :
//    labyrinthe : Le labyrinthe à résoudre
//    solution : le chemin le plus court trouvé jusqu'à maintenant
//    x,y : les coordonnées courantes de la souris
//*************************************************************************************
int trouverSorties(int labyrinthe[][TAILLE], int solution[][TAILLE], int x, int y)
{
  if (labyrinthe[x][y] != VIDE)
    return 0;
  
  labyrinthe[x][y] = SOURIS;
  
  if (x == TAILLE - 1 && y == TAILLE - 1)
  {
    if (longueurChemin(labyrinthe) <= longueurChemin(solution))
      copier(solution, labyrinthe);
    labyrinthe[x][y] = VIDE;
    return 1;
  }
  
  int s = (x + 1 < TAILLE && trouverSorties(labyrinthe, solution, x + 1, y));
	s |= (y + 1 < TAILLE && trouverSorties(labyrinthe, solution, x, y + 1));
	s |= (y - 1 >= 0 && trouverSorties(labyrinthe, solution, x, y - 1));
	s |= (x - 1 >= 0 && trouverSorties(labyrinthe, solution, x - 1, y));
  
  labyrinthe[x][y] = VIDE;
  return s;
}

//*********************************************************************************
// Pilote pour résoudre un labyrinthe
//*********************************************************************************
int main()
{
  int labyrinthe[][TAILLE] =
    {{VIDE, MUR, VIDE, VIDE, VIDE},
     {VIDE, VIDE, VIDE, MUR, VIDE},
     {VIDE, MUR, VIDE, VIDE, VIDE},
     {VIDE, MUR, VIDE, MUR, VIDE},
     {VIDE, VIDE, VIDE, MUR, VIDE}};
  
  int solution[TAILLE][TAILLE];
  for (int i = 0; i < TAILLE; i++)
    for (int j = 0; j < TAILLE; j++)
      solution[i][j] = (labyrinthe[i][j] == MUR ? MUR : SOURIS);
  
  printLabyrinthe(labyrinthe);
  
  if (trouverSorties(labyrinthe, solution, 0, 0))
    printLabyrinthe(solution);
  else
    printf("Pas de solution\n");
}
