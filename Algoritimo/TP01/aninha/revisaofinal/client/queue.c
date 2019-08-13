
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "queue.h"

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

int longueurQueue(Queue* queue){
    int numClient=0;
    Client* clientaux = queue->premier;
    while (clientaux != NULL){
        clientaux = clientaux->suivant;
        numClient++;
    }
    return numClient;
}

Client* coupDOeilTete(Queue* queue){
    return queue->premier;
}

Client* obtenirTete(Queue* queue){
    if(queue->premier != NULL){
        Client* delpremier = queue->premier; 
        queue->premier = delpremier->suivant; 
        free(delpremier); 
    }
        return queue->premier;
}

void delArticles(Queue* queue){
    if(queue->premier != NULL){
        Client* clientaux = queue->premier;
        clientaux->article--;
    }
}

void imprimerQueue(Queue* queue){
    Client* auxPrint = queue->premier;
    while(auxPrint != NULL){
        printf("{cycle #%d, %d articles}", auxPrint->cycle, auxPrint->article);
        auxPrint = auxPrint->suivant;
    }
    printf("\n");
}

double randExpo(double lambda){
    double u = rand() / (RAND_MAX + 1.0);
    return (-log(1 - u) / lambda) + 1;
}

void rapport(int nomClientsEntre, int nomArticlesVendus, int cycles, int nomArticlesMin, int nomArticlesMax, int tempsAttenteMax, int tempsAttenteMoyen)
{
    printf("\n");
    printf("Nombre de clients entrés : %d\n", nomClientsEntre);
    printf("Nombre d’articles vendus : %d\n", nomArticlesVendus);
    printf("Temps d’attente moyen    : %d cycles\n", (tempsAttenteMoyen)/nomClientsEntre);
    printf("Temps d’attente maximum  : %d cycles\n", tempsAttenteMax);
    printf("Nombre d’articles maximum: %d\n", nomArticlesMax);
    printf("Nombre d’articles minimum: %d\n", nomArticlesMin);
    printf("Nombre d’articles moyen  : %d\n", nomArticlesVendus/nomClientsEntre);
    printf("Nombre de cycles         : %d\n", cycles);
}
