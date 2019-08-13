
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
    
    //Cria e inicia as filas
    Queue* queue[NB_CAISSES];
    for (int i = 0; i < NB_CAISSES; i ++)
    {
        queue[i] = (Queue*) malloc(NB_CAISSES * sizeof(Queue));
        queue[i]->premier=NULL;
    }

    while(cont!=CYCLES){
        printf("\nETAT DES CAISSES AU CYCLE %i\n", cont);
        
        //Chance de 1 de 6 de entrar uma pessoa na fila
        probNew = rand() % PROB_MAX + PROB_MIN;
        
        if (probNew == 1){
            
            //Conta clientes que entrou
            numClientesEntrou++;
            
            //Cria cliente, aloca memoria e inicia.
            Client* p[cont];
            p[cont] = malloc(sizeof(Client));
            p[cont]->cycle = cont;
            p[cont]->article=randExpo(1.0/9);
            p[cont]->suivant = NULL;
            
            //Conta numero de artigos vendidos
            numArtigosVendidos=numArtigosVendidos+p[cont]->article;
            
            //Conta numero maximo de artigos
            if(p[cont]->article > numArtigosMaximo){
                numArtigosMaximo = p[cont]->article;
            }
            
            //Conta numero minimo de artigos
            if(numArtigosMin == 0 || numArtigosMin > p[cont]->article){
                numArtigosMin = p[cont]->article;
            }
            
            //Verifica a menor fila
            maior=0;menor=0;
            menor=longueurQueue(queue[1]);
            for(int i=0; i<NB_CAISSES; i++){
                
                if (longueurQueue(queue[i]) <= menor){
                    menor = longueurQueue(queue[i]);
                    maior=i;
                 }
            }
          
            //Adiciona no final da fila
            offrirClient(queue[maior], p[cont]);
        }
        
        //Diminui as compras de toda a fila
        for(int i=0;i<NB_CAISSES;i++){
            if(queue[i]->premier != NULL){
                
                deletaCompras(queue[i]);
                if (queue[i]->premier->article == 0){

               	//Calcula tempo maximo na fila por ciclo
                if((cont - queue[i]->premier->cycle) > tempoMaxAtendimento){
                    tempoMaxAtendimento = cont -queue[i]->premier->cycle;
                }
                //Calcula tempo medio
                tempoMedioAtendimento += cont - queue[i]->premier->cycle;

                    obtenirTete(queue[i]);
                }
            }
        }
        
        //Imprime filas para cada ciclo
        for(int i=3;i>=0; i--){
            printf("Caisse %d :", NB_CAISSES - i);
            imprimerQueue(queue[i]);
        }
        usleep(100000);
        cont++;
    }
    report(numClientesEntrou,numArtigosVendidos,CYCLES,numArtigosMin,numArtigosMaximo, tempoMaxAtendimento, tempoMedioAtendimento);
    return 0;
}
