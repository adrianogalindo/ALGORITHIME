// *****************************************************************************
//
// Nom : main.c
//
// Auteur : Adriano Galindo
//
// Date : 19 novembre de 2018
//
// execute le programme pour servir les clients dans les caisses.
//
// *****************************************************************************
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "queue.h"
#include "simulation.h"

// *****************************************************************************
// main
//
// sert a executer le programme. Il va rouler le programme dans une boucle et
// il va additioner les clients jusqu'au cycle de 200. aprés, va sulement
// servir les clients qui attend encore dans la queue.
//
// *****************************************************************************
int main()
{
	srand(time(NULL));
	Queue caisses[NB_CAISSES];
	Rapport rapport;
	int instant;
	rapport = initialiserRapport(rapport);
	initialiserCaisseNull(caisses);
	for (instant = 1; instant <= NB_CYCLE_MAX_POUR_AJOUTER_CLIENT || ilYAQuelquUn(caisses); instant++)
	{
		printf("ETAT DES CAISSES AU CYCLE #%d: \n", instant);
		if ((randomizeClient()) && (instant <= NB_CYCLE_MAX_POUR_AJOUTER_CLIENT))
			executerCreerEtOffrir(caisses, &rapport, instant);
		for (int i = 0; i < NB_CAISSES; i++)
		{
			Client* client = coupDOeilTete(caisses[i]);
			if (client != NULL)		
				retirerArticlesEtGererCaisse(client, &caisses[i], &rapport, instant);
			printf("Caisse(%d): ", i + 1);
			imprimerQueue(caisses[i]);
			printf("\n");
		}
		printRapport(rapport, instant);
		usleep(TEMP_DE_CYCLE_NORMAL);
		system("clear");
	}
	printRapport(rapport, instant - 1);
}