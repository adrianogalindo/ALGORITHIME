// *****************************************************************************
//
// Nom : queue.c
//
// Auteur : Adriano Galindo
//
// Date : 14 novembre de 2018
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


Client* creerClient(int instant, int nbArticles)
{
	Client* nouveau = (Client*)malloc(sizeof(Client));
	nouveau->instantArrivee = instant;
	nouveau->nbArticles = nbArticles;
	nouveau->suivant = NULL;
	nouveau->precedant = NULL;
	return nouveau;
}

// Ajoute le client a la fin de queue.
void offrirClient(Queue* queue, Client* client)
{
	if (queue->premier == NULL)
	{
		queue->premier = client;
		queue->dernier = client;
	}
	else
	{
		queue->dernier->suivant = client;
		client->precedant = queue->dernier;
		queue->dernier = client;
	}
}

// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* coupDOeilTete(Queue queue)
{
	if (queue.premier != NULL)
		return queue.premier;
	else
		return NULL;

}

// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* obtenirTete(Queue* queue)
{
	if (queue->premier != NULL)
	{
		Client* premierClient = queue->premier;
		queue->premier = queue->premier->suivant;
		return premierClient;
	}
	else
		return NULL;
}

// Retourne le nombre de clients dans la queue.
int longueurQueue(Queue queue)
{
	Client* c = queue.premier;
	int longueur = 0;
	while (c != NULL)
	{
		c = c->suivant;
		longueur++;
	}
	return longueur;
}

// Imprime chaque client de la queue.
void imprimerQueue(Queue queue)
{
	Client* c = queue.premier;
	while (c != NULL)
	{
		printf("{Cycle:%d, nbArticles:%d}", c->instantArrivee, c->nbArticles);
		c = c->suivant;
	}
}
