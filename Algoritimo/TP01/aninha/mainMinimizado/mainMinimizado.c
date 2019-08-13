
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "queue.h"

int main(){
	srand(time(NULL));
    int probNew, cont = 1, menor = 0, maior=0;
    int numClientesEntrou=0, numArtigosVendidos=0, tempoMaxAtendimento=0, numArtigosMaximo=0, numArtigosMin=0, tempoMedioAtendimento=0;
    Queue* queue[NB_CAISSES];
    for (int i = 0; i < NB_CAISSES; i ++)
    {
        queue[i] = (Queue*) malloc(NB_CAISSES * sizeof(Queue));
        queue[i]->premier=NULL;
    }
    while(cont!=CYCLES){
        printf("\nETAT DES CAISSES AU CYCLE %i\n", cont);
        probNew = rand() % PROB_MAX + PROB_MIN;
        if (probNew == 1){
            numClientesEntrou++;
            Client* p[cont];
            p[cont] = malloc(sizeof(Client));
            p[cont]->cycle = cont;
            p[cont]->article=randExpo(1.0/9);
            p[cont]->suivant = NULL;
            numArtigosVendidos=numArtigosVendidos+p[cont]->article;
            if(p[cont]->article > numArtigosMaximo)
                numArtigosMaximo = p[cont]->article;
            if(numArtigosMin == 0 || numArtigosMin > p[cont]->article)
                numArtigosMin = p[cont]->article;
            maior=0;menor=0;
            menor=longueurQueue(queue[1]);
            for(int i=0; i<NB_CAISSES; i++){
                
                if (longueurQueue(queue[i]) <= menor){
                    menor = longueurQueue(queue[i]);
                    maior=i;
                 }
            }
            offrirClient(queue[maior], p[cont]);
        }
        for(int i=0;i<NB_CAISSES;i++){
            if(queue[i]->premier != NULL){
                
                deletaCompras(queue[i]);
                if (queue[i]->premier->article == 0){
                if((cont - queue[i]->premier->cycle) > tempoMaxAtendimento){
                    tempoMaxAtendimento = cont -queue[i]->premier->cycle;
                }
                tempoMedioAtendimento += cont - queue[i]->premier->cycle;
                    obtenirTete(queue[i]);
                }
            }
        }
        for(int i=3;i>=0; i--){
            printf("Caisse %d :", NB_CAISSES - i);
            imprimerQueue(queue[i]);
        }
        usleep(TEMP_CYCLE_NORMAL);
        cont++;
    }
    report(numClientesEntrou,numArtigosVendidos,CYCLES,numArtigosMin,numArtigosMaximo, tempoMaxAtendimento, tempoMedioAtendimento);
    return 0;
}
