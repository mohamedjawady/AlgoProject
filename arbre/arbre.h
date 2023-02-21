#ifndef ARBRE_H_
#define ARBRE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef Node * TArbre;
typedef struct Node
{
    int occur;
    char val;
    TArbre fg;
    TArbre fd;
} Node;


TArbre arbreConsVide(void); int arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
void arbreSuppr(TArbre a);

// PRESENT IN EXTRAS: not visited by calls (directly/inderictly) from main.
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);

#endif
