#include <stdio.h>
#include <stdlib.h>

// variables globales, elles sont enregistrees dans la memoire statique
const int TAILLE = 10;

// ***********************************************************
// void imprimerTableau(int* tableau)
//
// Imprime le tableau a la console. Sa taille doit etre TAILLE
//
// INPUT : un tableau de taille TAILLE.
//
// ***********************************************************
void imprimerTableau(int* tableau)
{
    if (NULL == tableau)
    {
	printf("Le tableau est nul.\n");
    }
    else
    {
	printf("Contenu du tableau a l'adresse %p : \n", tableau);
	for (int j = 0; j < TAILLE; j++)
	{
	    printf("  %d^e case = %d\n", j, tableau[j]); 
	}
    }
    printf("\n");
}

// ***********************************************************
// int* fabriquerTableauPile()
//
// Fabrique un tableau dans la pile et met les nombres 1 a
// TAILLE dedans.
//
// Retourne l'adresse du tableau dans la pile.
//
// ***********************************************************
int* fabriquerTableauPile()
{
    int tableauPile[TAILLE];
  
    for (int j = 0; j < TAILLE; j++)
    {
	tableauPile[j] = j;
    }

    printf("***** Impression du tableau automatique dans fabriquerTableauPile ***** \n");
    imprimerTableau(tableauPile);

    return tableauPile;
}

// ***********************************************************
// int* fabriquerTableauTas()
//
// Fabrique un tableau dans le tas et met les nombres TAILLE a
// 1 dedans.
//
// Retourne l'adresse du tableau dans le tas.
//
// ***********************************************************
int* fabriquerTableauTas()
{
    int * tableauTas = (int *)malloc(TAILLE * sizeof(int));
    if (NULL == tableauTas)
    {
	fprintf(stderr, "malloc a échoué\n");
	return NULL;
    }
    for (int j = 0; j < TAILLE; j++)
    {
	tableauTas[j] = TAILLE - j; 
    }
    printf("***** Impression du tableau dynamique dans fabriquerTableauTas *****\n");
    imprimerTableau(tableauTas);
    return tableauTas;
}

// ***********************************************************
// int main()
//
// Appelle les deux fonctions de creation de tableau et imprime
// les tableaux recus.
//
// ***********************************************************
int main()
{
    int* tabPile = fabriquerTableauPile();
    int* tabTas = fabriquerTableauTas();

    printf("*************** Impression des tableaux dans le main ***************\n");
    imprimerTableau(tabPile);
    imprimerTableau(tabTas);
    //quando o endereço começa com 0x1 a memoria é estatica 
    printf("\nL'address de la fonction imprimerTableau est: %p\n", &imprimerTableau);
    printf("L'address de la constant TAILLE est: %p\n", &TAILLE);

    free(tabTas);

    printf("%d\n", sizeof(tabPile));
    printf("%d\n", sizeof(tabTas));
    int bitPasInitialise[10];
    imprimerTableau(bitPasInitialise);

    int* bitInitMalloc = (int*)malloc(sizeof(int)*10);
    imprimerTableau(bitInitMalloc);
    

    int* bitInitCalloc = (int*)calloc(sizeof(int),10);
    imprimerTableau(bitInitMalloc);
    free(bitInitCalloc);


    bitInitCalloc = realloc(bitInitMalloc, 20 * sizeof(int));
    for (int i = 0; i<20; i++)
        printf("%d\n", bitInitMalloc[i]);
    free(bitInitMalloc);

    return 0;
}
