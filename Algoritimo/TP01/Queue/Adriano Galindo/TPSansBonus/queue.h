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


#define NB_CAISSES 4
#define NB_MAX_CLIENT_PAR_QUEUE 1000000
#define CHANCE_MIN 1
#define CHANCE_MAX 6
#define NB_CYCLE_MAX_POUR_AJOUTER_CLIENT 200
#define TEMP_DE_CYCLE_NORMAL 1000000

// *****************************************************************************
// struct Client
//
// Crée un type qui sert à contenir les instant que le client arrive et
// le nombre d'articles que le client va acheter.
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
// creerClient
//
// Crée un nouveau client et guarde le instant, le nombre de article et point 
// pour un nouveau address dans la memoire.
//
// INPUT :
//     int instant: le instant que le client arrive.
//	   int nbArticles: le nombre d'articles que le client va acheter.
// OUTPUT :
//	   Un nouveau client avec l'instant arrivé, les nombre d'articles
//     puis pointe vers le prochaine client qui pourrait être crée.
//
// *****************************************************************************
Client* creerClient(int instant, int nbArticles);

// *****************************************************************************
// Pseudo code pour la function offrirClient
// function qui ajoute le client a la fin de queue.
//	 si queue->premier est different de NULL, alors
//		 Client^ clientDernier;
//		 Client^ clientTemporaire <- queue->premier
//		 Tant que clientTemporaire est different de NULL, faire
//			 clientDernier <- clientTemporaire
//			 clientTemporaire <- clientDernier->suivant
//		 clientDernier->suivant <- client
//	 Sinon, alors
//		 queue->premier <- client
// *****************************************************************************
// offrirClient
//
// Ajoute le client a la fin de queue.
//
// INPUT :
//     Queue* queue: le files
//	   Client* client: le client a ajouter dans la file
// OUTPUT :
//	   void: Change directement l'address de memoire avec pointeurs
//
// *****************************************************************************
void offrirClient(Queue* queue, Client* client);

// *****************************************************************************
// coupDOeilTete
//
// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
//
// INPUT :
//     Queue* queue: le files
// OUTPUT :
//	   queue: retourne queue.premier si n'est pas NULL
//      NULL; retourne null si le file n'est pas de client;
//
// *****************************************************************************
Client* coupDOeilTete(Queue queue);

// *****************************************************************************
// Pseudo Code pour la function obternirTete.
// function qui retire et retourne le premier client dans la queue
//	 Si queue->premier est different de NULL, alors
//	 	 Client^ premierClient <- queue->premier
//	 	 queue->premier <- queue->premier->suivant
//		 Retourner premierClient
//	 Sinon, alors
//		 Retourner NULL
// *****************************************************************************
// obtenirTete
//
// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
//
// INPUT :
//     Queue* queue: le files
// OUTPUT :
//	   queue: Retire et retourne le premier client si la file n'est pas NULL
//      NULL; retourne null si le file n'est pas de client;
//
// *****************************************************************************
Client* obtenirTete(Queue* queue);

// *****************************************************************************
// Pseudo code pour la function longueurQueue
// function qui retourne le nombre de clients dans la queue.
//	  Client^ c <- queue.premier
//	  longueur <- 0;
//    	 Tant que c est different de NULL, faire
//		 c <- c->suivant
//		 longueur <- longueur + 1
//	  Retourner longueur
// *****************************************************************************
// longueurQueue
//
// Retourne le nombre de clients dans la queue.
//
// INPUT :
//     Queue queue: le files
// OUTPUT :
//	   int longueur: le nombre de clients dans la file
//
// *****************************************************************************
int longueurQueue(Queue queue);

// *****************************************************************************
// imprimerQueue
//
// Imprime chaque client de la queue.
// 
// INPUT :
//     Queue queue: le files
// OUTPUT :
//	   rien (print de les queue)
// *****************************************************************************
void imprimerQueue(Queue queue);

