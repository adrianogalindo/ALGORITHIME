#include <stdio.h>
#include <stdlib.h>
#define BUFF 4

typedef struct TabDyn TabDyn;
struct TabDyn{
	double* tab;
	int dernier;
	int taille;
};


void initialiser(TabDyn* tabDyn)
{
	(*tabDyn).tab = (double*)malloc(BUFF * sizeof(double));  //tabDyn->tab (meme chose)
	(*tabDyn).dernier = 0;
	(*tabDyn).taille = BUFF;
}

int ajouterElement(TabDyn* tabDyn, double e)
{	
	(*tabDyn).tab[(*tabDyn).dernier] = e;
	(*tabDyn).dernier++;
	if ((*tabDyn).dernier >= (*tabDyn).taille)
	{
		(*tabDyn).taille += BUFF;
 		(*tabDyn).tab = (double*)realloc((*tabDyn).tab, (*tabDyn).taille * sizeof(double));
 	}
 	return 1;
}

void libererMemoire(TabDyn* tabDyn)
{
	free((*tabDyn).tab);
}


int main()
{
	TabDyn tabDyn;
	initialiser(&tabDyn);
	double a;
	do{
 		scanf("%lf", &a);
 		if (!ajouterElement(&tabDyn, a))
 			return -1;
	}while (a >= 0);

	for (int i = 0; i < tabDyn.dernier - 1; i++)
		printf("%lf ", tabDyn.tab[i]);
	libererMemoire(&tabDyn);
}
