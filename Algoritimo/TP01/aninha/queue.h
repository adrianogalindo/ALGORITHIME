
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

typedef struct Client Client;
struct Client{
    int cycle, article;
    Client* suivant;
};

typedef struct Queue Queue;
struct Queue{
    //Armazena tamanho da lista
    Client* premier;
    
};

void offrirClient(Queue* queue, Client* client);

// Retourne le nombre de clients dans la queue.
int longueurQueue(Queue* queue);

// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* coupDOeilTete(Queue* queue);

// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* obtenirTete(Queue* queue);

// Diminui o numero de compras de todos da fila
void deletaCompras(Queue* queue);

// Imprime chaque client de la queue.
void imprimerQueue(Queue* queue);

//Gera randon de artigos
double randExpo(double lambda);

//Gera relatorio
void report(int numClientesEntrou, int numArtigosVendidos, int ciclos, int numArtigosMin, int numArtigosMaximo, int tempoMaxAtendimento, int tempoMedioAtendimento);

