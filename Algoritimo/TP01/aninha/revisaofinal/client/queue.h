
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define CYCLES 200
#define PROB_MIN 1
#define PROB_MAX 6
#define NB_CAISSES 4
#define TEMP_CYCLE_NORMAL 1000000


// ************************************************************
// La struct Cient crée le client
// 
// *************************************************************
typedef struct Client Client;
struct Client{
    int cycle, article;
    Client* suivant;
};

// ************************************************************
// La struct Queue stocke la taille de la file d'attente
// 
// *************************************************************
typedef struct Queue Queue;
struct Queue{
  
    Client* premier;
    
};
// ************************************************************
// void offrirClient(Queue* queue, Client* client);
//  Ajoute le client a la fin de queue.
// - INPUT: stocke le client dans la file d'attente
//
//
// -  Pseudo-code:
// Si queue->premier est égal a Null, alors
//    queue -> premier <- client
// Sinon, alors
//    Client^ aux
//    aux <- malloc taille de client
//    aux -> suivant <- queue -> premier
//    Tant que aux -> suivant est different de Null, faire
//        aux <- aux -> suivant
//    aux -> suivant <- client 
// *************************************************************
void offrirClient(Queue* queue, Client* client);

//*************************************************************
// int longueurQueue(Queue* queue)
// Retourne le nombre de clients dans la queue.
//
//
// -  Pseudo-code:
//   numClient <- 0
//   Client^ clientaux <- queue -> premier
//   Tant que clientaux est different de NULL, faire
//     clientaux <- clientaux -> suivant
//     numClient <- numClient + 1
//   Retourner numClient
// *************************************************************
int longueurQueue(Queue* queue);

//*************************************************************
// Client* obtenirTete(Queue* queue)
// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
//
//
// -  Pseudo-code:
//  Si queue -> premier est diferrent de NULL, alors
//    Client^ delpremier <- queue -> premier
//    queue -> premier <- delpremier -> suivant
//    libérer delpremier
//    Retourner queue -> premier
//************************************************************
Client* obtenirTete(Queue* queue);

//************************************************************
// void delArticles(Queue* queue);
// Diminuer le nombre d'achats de toutes les personnes dans la file d'attente.
//************************************************************
void delArticles(Queue* queue);

//************************************************************
// void imprimerQueue(Queue* queue);
// Imprime chaque client de la queue.
//************************************************************
void imprimerQueue(Queue* queue);

//************************************************************
// double randExpo(double lambda);
// Génère randon des articles
//************************************************************
double randExpo(double lambda);

//************************************************************
// void rapport
//Génère un rapport
//************************************************************
void rapport(int nomClientsEntre, int nomArticlesVendus, int cycles, int nomArticlesMin, int nomArticlesMax, int tempsAttenteMax, int tempsAttenteMoyen);

