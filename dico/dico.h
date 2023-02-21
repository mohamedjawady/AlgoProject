#ifndef DICO_H_
#define DICO_H_
#include "../arbre/arbre.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void affichageRec(TArbre a, char *str, short bufidx);
void dicoInsererMot(char mot[], TArbre *pa);
int dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a); 
int dicoNbMotsTotal(TArbre a);

#endif