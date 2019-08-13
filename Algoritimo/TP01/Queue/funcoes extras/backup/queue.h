// *****************************************************************************
//
// Nom : queue.h
//
// Auteur : Adriano Galindo
//
// Date : 13 novembre de 2018
//
// Liste des signiatures des fonctions et structures pour le programme queue.c
//
// *****************************************************************************
#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NOM_CAISSE 4
#define NB_MAX_CLIENT_PAR_QUEUE 100
#define NB_MOYEN_DARTICLES_PAR_CLIENT 11


// *****************************************************************************
// struct Client
//
// Crée un type qui sert à contenir les instant que le client arrive et
// le nombre de articles que le client va acheter.
// Crée aussi une liste double chainé pour pointer le client suivant et
// le precedant
//
// *****************************************************************************
typedef struct Client Client;
struct Client{
	int instantArrivee; 	
	int nbArticles;			
	Client* suivant; 
	Client* precedant;		
};

// *****************************************************************************
// struct Queue
//
// Crée un type qui sert à contenir le premier e le dernier client qui le
// pointer de la structure Client va pointer.
//
// *****************************************************************************
typedef struct Queue Queue;
struct Queue{
	Client* premier;
	Client* dernier;
};

// *****************************************************************************
// struct Rapport
//
// Crée un type qui sert à contenir le donnés qui vont être utilisé dans le
// rapport affiché
//
// *****************************************************************************
typedef struct Rapport Rapport;
struct Rapport{
	int nombreDeClientsEntres;
	int nombreDArticlesVendus;
	int tempsDAttenteMoyen;
	int tempsDAttenteMaximum;
	int nombreDArticlesMaximum;
	int nombreDArticlesMinimum;
};

// *****************************************************************************
// initialiserRapport
//
// Initialize les variables du rapport
//
// INPUT :
//     une variable de la structure de type Rapport
// OUTPUT :
//     Les valeurs de tous les cases du score à 0
//
// *****************************************************************************
Rapport initialiserRapport(Rapport rapport);


double randExpo(double lambda);


int randomizeClient();


Client* creerClient(int instant, int nbArticles);



// Ajoute le client a la fin de queue.
void offrirClient(Queue* queue, Client* client);


// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* coupDOeilTete(Queue queue);


// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* obtenirTete(Queue* queue);


// Retourne le nombre de clients dans la queue.
int longueurQueue(Queue queue);

// Imprime chaque client de la queue.
void imprimerQueue(Queue queue);


void printRapport(Rapport rapport, int instant);


void initialiserCaisseNull(Queue* queue);


int ilYAQuelquUn(Queue* queue);


int caisseAvecMoinsClient(Queue* queue);


void executerCreerEtOffrir(Queue* queue, Rapport* rapport, int instant);

