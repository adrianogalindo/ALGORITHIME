// *****************************************************************************
//
// Nom : simulation.c
//
// Auteur : Adriano Galindo
//
// Date : 19 novembre de 2018
//
// Implement une structure de donnees unidimensionelle pour une programme qui
// simule le sisteme de caisses de une marche.
//
// *****************************************************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "queue.h"
#include "simulation.h"

Rapport initialiserRapport(Rapport rapport)
{
	rapport.nombreDeClientsEntres = 0;
	rapport.nombreDArticlesVendus = 0;
	rapport.tempsDAttenteMoyen = 0;
	rapport.tempsDAttenteMaximum = 0;
	rapport.nombreDArticlesMaximum = 0;
	rapport.nombreDArticlesMinimum = 0;
	return rapport;
}

double randExpo(double lambda)
{
    double u = rand() / (RAND_MAX + 1.0);
    return (-log(1 - u) / lambda) + 1;
}

int randomizeClient()
{
    if ((rand() % CHANCE_MAX + CHANCE_MIN) == 1)
    	return 1;
    else
    	return 0;
}


void printRapport(Rapport rapport, int instant)
{
	printf("\n");
	printf("*********************************************\n");
	printf("* Nombre de clients entrés  : %.5d         *\n", rapport.nombreDeClientsEntres);
	printf("* Nombre d’articles vendus  : %.5d         *\n", rapport.nombreDArticlesVendus);
	printf("* Temps d’attente moyen     : %.5d cycles  *\n", (rapport.tempsDAttenteMoyen > 0)? rapport.tempsDAttenteMoyen / rapport.nombreDeClientsEntres : 0);
	printf("* Temps d’attente maximum   : %.5d cycles  *\n", rapport.tempsDAttenteMaximum);
	printf("* Nombre d’articles maximum : %.5d         *\n", rapport.nombreDArticlesMaximum);
	printf("* Nombre d’articles minimum : %.5d         *\n", rapport.nombreDArticlesMinimum);
	printf("* Nombre d’articles moyen   : %.5d         *\n", (rapport.nombreDeClientsEntres > 0)? rapport.nombreDArticlesVendus / rapport.nombreDeClientsEntres : 0);
	printf("* Nombre de cycles          : %.5d         *\n", instant);
	printf("*********************************************\n");
}

void initialiserCaisseNull(Queue* queue)
{
	for (int i = 0; i < NB_CAISSES; i++)
	{
		queue[i].premier = NULL;
		queue[i].dernier = NULL;
	}
}

int ilYAQuelquUn(Queue* queue)
{
	for (int i = 0; i < NB_CAISSES; i++)
		if(queue[i].premier != NULL)
			return 1;
	return 0;
}

int caisseAvecMoinsClient(Queue* queue)
{
	int comptQueueCaisse = 0;							
	int queuePlusPetit = NB_MAX_CLIENT_PAR_QUEUE;
	int nombreDeCaisse = 0;			
	for (int i = 0; i < NB_CAISSES; i++)                 
	{
		comptQueueCaisse = longueurQueue(queue[i]);
		if (comptQueueCaisse < queuePlusPetit)
		{
			queuePlusPetit = comptQueueCaisse;
			nombreDeCaisse = i;
		}
	}
	return nombreDeCaisse;												
}

void executerCreerEtOffrir(Queue* queue, Rapport* rapport, int instant)
{
	Client* nouveau = creerClient(instant, randExpo(1.0/9));
	offrirClient(&queue[caisseAvecMoinsClient(queue)], nouveau);
	
	//rapport->nombreDArticlesVendus += nouveau->nbArticles;
	if (rapport->nombreDArticlesMaximum < nouveau->nbArticles)
		rapport->nombreDArticlesMaximum = nouveau->nbArticles;
	if (rapport->nombreDArticlesMinimum == 0 || rapport->nombreDArticlesMinimum > nouveau->nbArticles)
		rapport->nombreDArticlesMinimum = nouveau->nbArticles;
	rapport->nombreDeClientsEntres++;
}

void retirerArticlesEtGererCaisse(Client* client, Queue* queue, Rapport* rapport, int instant)
{
	client->nbArticles--;
	rapport->nombreDArticlesVendus ++;
	if (client->nbArticles == 0)
	{
	    if ((instant - client->instantArrivee) > rapport->tempsDAttenteMaximum)
	        rapport->tempsDAttenteMaximum = instant - client->instantArrivee;
	    rapport->tempsDAttenteMoyen += instant - client->instantArrivee;
		obtenirTete(queue);
		free(client);
	}
}

