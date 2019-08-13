#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimerTableau(int tab[], int n)
{
  for (int i = 0; i < n; i ++)
    printf("%d%s", tab[i], ((i < n - 1) ? ", " : "\n"));
}

void echanger(int* a, int* b)
{
  int t = *b;
  *b = *a;
  *a = t;
}

// début inclusif
// milieu à droite
// fin exclufif
void fusionner(int in[], int out[], int debut, int milieu, int fin)
{
  int a = debut;
  int b = milieu;
  for (int i = debut; i < fin; i++)
    if ((a < milieu) && ((in[a] < in[b]) || (b >= fin)))
      out[i] = in[a++];
    else
      out[i] = in[b++];
}

// debut inclusif, fin exclusif
void triFusion(int in[], int out[], int debut, int fin)
{
  if (fin - debut < 2)
    return;
  int milieu = (debut + fin) / 2;

  triFusion(out, in, debut, milieu);
  triFusion(out, in, milieu, fin);
  fusionner(in, out, debut, milieu, fin);
}

void triBulle(int in[], int fin)
{ 
  int i,j,temp;
      
  for (i= fin - 1; i > 0 ; i--)
    for (j = 1;j <= i; j++)
    {
      if (in[j - 1] > in[j])
      {
        temp = in[j - 1];
        in[j - 1] = in[j];
        in[j] = temp;
      }
    }
}

void triInsertion(int insertionTab[],int fin)
{
  int i, memory, compt, marqueur;

  for(i = 1; i < fin; i++)
  {
    memory = insertionTab[i];
    compt = i - 1;
    do {
      marqueur = 0;
      if (insertionTab[compt] > memory)
      {
        insertionTab[compt + 1] = insertionTab[compt];
        compt--;
        marqueur = 1;
      }
      if (compt < 0)
        marqueur = 0;
      } while(marqueur);
      insertionTab[compt + 1] = memory;
  }
}

int main()
{
  srand(time(NULL));
  const int TAILLE = 1000000;
  int tab[TAILLE];
  int* fusionTabIn = (int*)malloc(TAILLE * sizeof(int));
  int* fusionTabOut = (int*)malloc(TAILLE * sizeof(int));
  int* bulleTab = (int*)malloc(TAILLE * sizeof(int));
  int* insertionTab = (int*)malloc(TAILLE * sizeof(int));

  for (int i = 0; i < TAILLE; i++)
  {
    tab[i] = rand() % TAILLE;
    fusionTabIn[i] = tab[i];
    fusionTabOut[i] = tab[i];
    bulleTab[i] = tab[i];
    insertionTab[i] = tab[i];
  }
  printf("DÉBUT TRI FUSION\n");
  // imprimerTableau(tab, TAILLE); 

  clock_t debut1 = clock();
  triFusion(fusionTabIn, fusionTabOut, 0, TAILLE);

  clock_t fin1 = clock();
  printf("\nFIN TRI FUSION (%lf secondes)\n", (double)(fin1-debut1)/CLOCKS_PER_SEC);
  // imprimerTableau(tab, TAILLE);
  printf("\n\n\n");

  //TRI BULLE
  printf("DÉBUT TRI BULLE\n");
  // imprimerTableau(tab, TAILLE); 

  clock_t debut2 = clock();
  triBulle(bulleTab, TAILLE);

  clock_t fin2 = clock();
  printf("\nFIN TRI BULLE (%lf secondes)\n", (double)(fin2-debut2)/CLOCKS_PER_SEC);
  // imprimerTableau(bulleTab, TAILLE);
  printf("\n\n\n");

    //TRI INSERTION
  printf("DÉBUT TRI INSERTION\n");
  // imprimerTableau(tab, TAILLE); 

  clock_t debut3 = clock();
  triInsertion(insertionTab, TAILLE);

  clock_t fin3 = clock();
  printf("\nFIN TRI INSERTION (%lf secondes)\n", (double)(fin3-debut3)/CLOCKS_PER_SEC);
  // imprimerTableau(insertionTab, TAILLE);
  printf("\n\n\n");
}
