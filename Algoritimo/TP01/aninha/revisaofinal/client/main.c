
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "queue.h"

int main(){
	srand(time(NULL));
    int nouvProbabil, cont = 1, min = 0, max=0;
    int nomClientsEntre=0, nomArticlesVendus=0, tempsAttenteMax=0, nomArticlesMax=0, nomArticlesMin=0, tempsAttenteMoyen=0;
    Queue* queue[NB_CAISSES];
    for (int i = 0; i < NB_CAISSES; i ++)
    {
        queue[i] = (Queue*) malloc(NB_CAISSES * sizeof(Queue));
        queue[i]->premier=NULL;
    }
    while(cont!=CYCLES){
        printf("\nETAT DES CAISSES AU CYCLE %i\n", cont);
        nouvProbabil = rand() % PROB_MAX + PROB_MIN;
        if (nouvProbabil == 1){
            nomClientsEntre++;
            Client* p[cont];
            p[cont] = malloc(sizeof(Client));
            p[cont]->cycle = cont;
            p[cont]->article=randExpo(1.0/9);
            p[cont]->suivant = NULL;
            nomArticlesVendus=nomArticlesVendus+p[cont]->article;
            if(p[cont]->article > nomArticlesMax)
                nomArticlesMax = p[cont]->article;
            if(nomArticlesMin == 0 || nomArticlesMin > p[cont]->article)
                nomArticlesMin = p[cont]->article;
            max=0;min=0;
            min=longueurQueue(queue[1]);
            for(int i=0; i<NB_CAISSES; i++){
                
                if (longueurQueue(queue[i]) <= min){
                    min = longueurQueue(queue[i]);
                    max=i;
                 }
            }
            offrirClient(queue[max], p[cont]);
        }
        for(int i=0;i<NB_CAISSES;i++){
            if(queue[i]->premier != NULL){
                
                delArticles(queue[i]);
                if (queue[i]->premier->article == 0){
                if((cont - queue[i]->premier->cycle) > tempsAttenteMax){
                    tempsAttenteMax = cont -queue[i]->premier->cycle;
                }
                tempsAttenteMoyen += cont - queue[i]->premier->cycle;
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
    rapport(nomClientsEntre,nomArticlesVendus,CYCLES,nomArticlesMin,nomArticlesMax,tempsAttenteMax, tempsAttenteMoyen);
    return 0;
}
