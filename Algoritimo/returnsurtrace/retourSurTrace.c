//*********************************************************
// retourSurTrace.c
// Rébecca
// 30 novembre 2018
//
// Exemple de retour sur trace : les dames
//*********************************************************
#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

int compt = 0;

//*********************************************************
// int libre(int echiquier[TAILLE][TAILLE], int x, int y)
// Détermine si la case (x,y) est libre dans l'échiquier
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//    x, y : les coordonnées de la case dans l'échiquier
//
// OUTPUT : 
//    1 si la case x,y est libre, 0 sinon.
//*********************************************************
int libre(int echiquier[TAILLE][TAILLE], int x, int y)
{
  for (int i = 0; i < TAILLE; i++)
  {
    if (echiquier[x][i] || echiquier[i][y])
      return 0;
    for (int j = 0; j < TAILLE; j++)
      if (echiquier[i][j] && ((i + j == x + y) || (i - j == x - y)))
	     return 0;
  }
  return 1;
}

//*********************************************************
// void printEchiquier(int echiquier[TAILLE][TAILLE])
// Imprime l'échiquier à la console.
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//*********************************************************
void printEchiquier(int echiquier[TAILLE][TAILLE])
{
  for (int i = 0; i < TAILLE; i++)
  {
    for (int j = 0; j < TAILLE; j++)
      printf("%d ", echiquier[i][j]);
    printf("\n");
  }
}

//*********************************************************
// int dames(int echiquier[TAILLE][TAILLE], int nbDames)
// Détermine si nbDames dames peuvent être placées dans 
// l'échiquier sans qu'une puisse en manger une autre.
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//    nbDames : le nombre de dames à placer
//
// OUTPUT : 
//    1 si nbDames peuvent être placées dans l'échiquier
//    0 sinon.
//*********************************************************
int dames(int echiquier[TAILLE][TAILLE], int nbDames)
{

  if (nbDames == 0)
  {
    //printEchiquier(echiquier);
    compt++;
    printf("Nombres de possibilité: %d\n", compt);
  }  //return 1;
  int i = TAILLE - nbDames;
  for (int j = 0; j < TAILLE; j++)
  {  
    if (libre(echiquier, i, j))
    {
      echiquier[i][j] = 1;
      if(dames(echiquier, nbDames - 1))
      {  
        return 1;
      }
      echiquier[i][j] = 0;
    }
  }

  return 0;
}

int chemin(int labyrinthe[TAILLE][TAILLE], int x, int y)
{

  if (labyrinthe[4][4] == 2)
    return 1;
  int i = TAILLE - ;
  for (int j = 0; j < TAILLE; j++)
  {  
    if (libre(echiquier, i, j))
    {
      echiquier[i][j] = 1;
      if(dames(echiquier, nbDames - 1))
      {  
        return 1;
      }
      echiquier[i][j] = 0;
    }
  }

  return 0;
} 
//*********************************************************
// Pilote pour le problème des dames.
//*********************************************************
int main()
{
	int cheminCorrect[TAILLE][TAILLE] = {{0,1,0,0,0},{0,0,0,1,0},{0,1,0,1,0},{0,1,0,0,0},{0,0,0,1,0}};

  	int echiquier[TAILLE][TAILLE];


  // for (int i = 0; i < TAILLE; i++)
  //   for (int j = 0; j < TAILLE; j++)
  //     echiquier[i][j] = 0;
  dames(echiquier, TAILLE); 
  //printEchiquier(echiquier);  
}
