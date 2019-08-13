// ****************************************************************************
// fonctions.c
// 26 novembre 2018
// Adriano Galindo, Ana Urias et Nicolle Falbo
// contient les fonctions pour le programme Boggle
// ****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 4
#define C 4
#define NB_FACES 6
#define NB_FACE_MIN 0
#define NB_FACE_MAX 5
#define NB_DES 16
#define CASE_MAX 15
#define CASE_MIN 0

/** Les 16 des officiels du jeu de boggle en francais */
const char DES[R * C][NB_FACES] =
{{'E', 'T', 'U', 'K', 'N', 'O'},  // 0
 {'E', 'V', 'G', 'T', 'I', 'N'},  // 1
 {'D', 'E', 'C', 'A', 'M', 'P'},  // 2
 {'I', 'E', 'L', 'R', 'U', 'W'},  // 3
 {'E', 'H', 'I', 'F', 'S', 'E'},  // 4
 {'R', 'E', 'C', 'A', 'L', 'S'},  // 5
 {'E', 'N', 'T', 'D', 'O', 'S'},  // 6
 {'O', 'F', 'X', 'R', 'I', 'A'},  // 7
 {'N', 'A', 'V', 'E', 'D', 'Z'},  // 8
 {'E', 'I', 'O', 'A', 'T', 'A'},  // 9
 {'G', 'L', 'E', 'N', 'Y', 'U'},  // 10
 {'B', 'M', 'A', 'Q', 'J', 'O'},  // 11
 {'T', 'L', 'I', 'B', 'R', 'A'},  // 12
 {'S', 'P', 'U', 'L', 'T', 'E'},  // 13
 {'A', 'I', 'M', 'S', 'O', 'R'},  // 14
 {'E', 'N', 'H', 'R', 'I', 'S'}}; // 15

//https://www.quora.com/What-is-a-simple-implementation-of-the-Fisher%E2%80%93Yates-shuffle-in-C
void fisherYatesShuffle(int* nombreDesSortie, int n)
{
    int j,temp;
    for(int i = n - 1; i >= 0; i--)
    {
        int j = rand()%(i + 1);
  //swap
        int temp = nombreDesSortie[j];
        nombreDesSortie[j] = nombreDesSortie[i];
        nombreDesSortie[i] = temp;
    }
}

void remplirGrille(char** DES, char** grille, int* nombreDesSortie)
{
    fisherYatesShuffle(nombreDesSortie, NB_DES);
    int compt = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            grille[i][j] = DES[nombreDesSortie[compt]][rand() % NB_FACE_MAX + NB_FACE_MIN];
            compt++;
        }
}



int main()
{   
    srand(time(NULL));
    int nombreDesSortie[NB_DES];
    for (int i = 0; i < NB_DES; i++)
        nombreDesSortie[i] = i;
        

    fisherYatesShuffle(nombreDesSortie, NB_DES);
    for (int i = 0; i < NB_DES; i++)
        printf("%d , ", nombreDesSortie[i]);
        
}