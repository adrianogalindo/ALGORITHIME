
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "queue.h"




// Ajoute le client a la fin de queue.
void offrirClient(Queue* queue, Client* client){
    if (queue->premier == NULL){
        queue->premier = client;
    }
    else{
        Client* aux;
        aux = malloc(sizeof(Client));
        aux->suivant = queue->premier;
        
        while(aux->suivant != NULL){
            aux = aux->suivant;
        }
        aux->suivant = client;
    }
}

// Retourne le nombre de clients dans la queue.
int longueurQueue(Queue* queue){
    int numClient=0;
    Client* clientaux = queue->premier;
    while (clientaux != NULL){
        clientaux = clientaux->suivant;
        numClient++;
    }
    return numClient;
}

// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* coupDOeilTete(Queue* queue){
    return queue->premier;
}

// Retire et retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
Client* obtenirTete(Queue* queue){
    if(queue->premier != NULL){
        Client* delpremier = queue->premier; //Auxiliar que aponta para a cabeca da lista
        queue->premier = delpremier->suivant; //Troca a cabeca da lista para o proximo
        free(delpremier); //Deleta a antiga cabeca
    }
        return queue->premier;
}

// Diminui o numero de compras de todos da fila
void deletaCompras(Queue* queue){
    if(queue->premier != NULL){
        Client* clientaux = queue->premier;
        clientaux->article--;
    }
}

// Imprime chaque client de la queue.
void imprimerQueue(Queue* queue){
    Client* auxPrint = queue->premier;
    while(auxPrint != NULL){
        printf("{cycle #%d, %d articles}", auxPrint->cycle, auxPrint->article);
        auxPrint = auxPrint->suivant;
    }
    printf("\n");
}

//Gera randon de artigos
double randExpo(double lambda){
    double u = rand() / (RAND_MAX + 1.0);
    return (-log(1 - u) / lambda) + 1;
}

//Gera relatorio
void report(int numClientesEntrou, int numArtigosVendidos, int ciclos, int numArtigosMin, int numArtigosMaximo, int tempoMaxAtendimento, int tempoMedioAtendimento)
{
    printf("\n");
    printf("Nombre de clients entrés : %d\n", numClientesEntrou);
    printf("Nombre d’articles vendus : %d\n", numArtigosVendidos);
    printf("Temps d’attente moyen    : %d cycles\n", (tempoMedioAtendimento)/numClientesEntrou);
    printf("Temps d’attente maximum  : %d cycles\n", tempoMaxAtendimento);
    printf("Nombre d’articles maximum: %d\n", numArtigosMaximo);
    printf("Nombre d’articles minimum: %d\n", numArtigosMin);
    printf("Nombre d’articles moyen  : %d\n", numArtigosVendidos/numClientesEntrou);
    printf("Nombre de cycles         : %d\n", ciclos);
}
