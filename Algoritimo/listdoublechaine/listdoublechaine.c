#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;
struct Noeud{
	Noeud* precedent;
	int donnee;
	Noeud* suivant;
};

typedef struct Queue Queue;
struct Queue{
	Noeud* premier;
};

void imprimerQueue(Queue queue)
{
	Noeud* c = queue.premier;
	while (c != NULL)
	{	
		printf("{%d} ", c->donnee);
		c = c->suivant;
	}
	printf("\n");
}

void retirerValeur(Queue* queue, int valeur)
{
	Noeud* trier = queue->premier;
	while (trier != NULL)
	{	
		if (trier->donnee == 44)
		{	
			if (trier->suivant != NULL)
				trier->suivant->precedent = trier->precedent;
			if (trier->precedent != NULL)
				trier->precedent->suivant = trier->suivant;
			else
				queue->premier = trier->suivant;
		}
		trier = trier->suivant;
	}
}

int main()
{


	Noeud premier;
	premier.donnee = 10;
	Noeud deuxieme;
	deuxieme.donnee = 44;
	Noeud troisieme;
	troisieme.donnee = 20;
	premier.precedent = NULL;
	premier.suivant = &deuxieme;
	deuxieme.precedent = &premier;
	deuxieme.suivant = &troisieme;
	troisieme.precedent = &deuxieme;
	troisieme.suivant = NULL;

	Queue trier;
	trier.premier = &premier;

	imprimerQueue(trier);
	retirerValeur(&trier, 44);
	imprimerQueue(trier);





}