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

// *****************************************************************************
// randExpo
//
// Prendre un nombre au hazard au moyene de 10.
// Sert pour prendre le nombre de artibcles pour le client.
//
// INPUT :
//     Double lambda: un nombre du type double
// OUTPUT :
//     un nombre au hazard au moyen de 10.
//
// *****************************************************************************
double randExpo(double lambda);

// *****************************************************************************
// randomizeClient
//
// prendre un nombre de 1 a 6 au hazard et on utilise l'heure comme "germe"
// la fonction utilize la percentage de 1/6 de chance pour ajouter un client.
//
// OUTPUT :
//     1 : ajouter un nouveau client
//	   2, 3, 4, 5 ou 6: n'ajoute pas un nouveau client 
//
// *****************************************************************************
int randomizeClient();

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

// *****************************************************************************
// printRapport
//
// Imprime le rapport de donnes
//
// INPUT :
//     Rapport rapport: le variable qui contient les donnes du rapport
//     int instant: le instante general du programme
// OUTPUT :
//	   rien (print le rapport)
//
// *****************************************************************************
void printRapport(Rapport rapport, int instant);

// *****************************************************************************
// initialiserCaisseNull
//
// initialise les caisses NULL
//
// INPUT :
//     Queue* queue: les caisses qui vont servir les clients
// OUTPUT :
//	   rien
//
// *****************************************************************************
void initialiserCaisseNull(Queue* queue);

// *****************************************************************************
// ilYAQuelquUn
//
// Verifie si il y a quelque client encora dans chaque queue
//
// INPUT :
//     Queue* queue: les caisses
// OUTPUT :
//	   1: Si a quelqu'un dans la file
//     0: Si n'a pas qulequ'un dans les files
//
// *****************************************************************************
int ilYAQuelquUn(Queue* queue);

// *****************************************************************************
// caisseAvecMoinsClient
//
// Retourne le caisse que il y a moins client
//
// INPUT :
//     Queue* queue: les caisses
// OUTPUT :
//	   le nombre de le caisse avec moins client
//
// *****************************************************************************
int caisseAvecMoinsClient(Queue* queue);

// *****************************************************************************
// executerCreerEtOffrir
//
// Sert pour executer les actions de creer e offrir les nouveau clients
//
// INPUT :
//     Queue* queue: les caisses
//     Rapport* rapport: le feuille de rapport de donnes
//     int instant: le instant general d'execution de cycle
// OUTPUT :
//	   rien
//
// *****************************************************************************
void executerCreerEtOffrir(Queue* queue, Rapport* rapport, int instant);

// *****************************************************************************
// retirerArticlesEtGererCaisse
//
// Sert pour retirer les articles du premier client de chaque queue
// si la queue etre null, retire le premier client de la queue et 
// serve le prochaine
//
// INPUT :
//     Queue* queue: les caisses
//     Rapport* rapport: le feuille de rapport de donnes
//     int instant: le instant general d'execution de cycle
// OUTPUT :
//	   rien
//
// *****************************************************************************
void retirerArticlesEtGererCaisse(Client* client, Queue* queue, Rapport* rapport, int instant);

