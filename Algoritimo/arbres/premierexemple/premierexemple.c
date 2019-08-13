#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;
struct Noeud{
    char donnee;
    Noeud* g;
    Noeud* d;
};




int main(int argc, char** argv){
 Noeud a = {'A', NULL, NULL};
 Noeud c = {'C', NULL, NULL};
 Noeud b = {'B', &a, &c};
 Noeud e = {'E', NULL, NULL};
 Noeud f = {'F', &e, NULL};
 Noeud racine = {'D', &b, &f};


printf("%c", racine.g->g->donnee);
printf("\n");
printf("%c", racine.g->d->donnee);
printf("\n");
printf("%c", racine.d->g->donnee);
printf("\n");

}