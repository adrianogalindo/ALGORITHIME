// *****************************************************************************
//
// Nom : simulation.h
//
// Auteur : Adriano Galindo
//
// Date : 19 novembre de 2018
//
// Liste des signiatures des fonctions et structures pour le programme simulation.c
//
// *****************************************************************************
#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
