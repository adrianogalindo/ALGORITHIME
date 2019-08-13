#include <stdio.h>
#include <stdlib.h>

void imprimerTableau(int* tableau, int taille)
{
    printf("Contenu du tableau a l'adresse %p : \n", tableau);
	for (int j = 0; j < taille; j++)
	    printf("  %d^e case = %d\n", j, tableau[j]); 
    printf("\n");
}

int* copie(int* tableau, int taille)
{
	int destination[taille];
	
	for (int i = 0; i < taille; i++)
		destination[i] = tableau[i];
	imprimerTableau(destination, taille);
	return destination;
}

void copie2(int* tableau, int* destination, int taille)
{
	for (int i = 0; i < taille; i++)
		destination[i] = tableau[i];
	imprimerTableau(destination, taille);	
}

int main()
{
	int tab[5] = {99, 5, 3, 19, -88};
	int* copieTab = copie(tab, 5);
	int destination[5];
	copie2(tab, destination, 5);
	imprimerTableau(tab, 5);
	imprimerTableau(copieTab, 5);
	imprimerTableau(destination, 5);
}