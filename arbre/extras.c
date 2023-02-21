#include "arbre.h"


char arbreRacineLettre(TArbre a){
    /* Returns the char char of a TArbre a root node.
     * */
    if (a )
    {
        return a->val;
    }
    return (char)0;
}

int arbreRacineNbOcc(TArbre a){
    /* Returns the number of occurences in the root node.
     * */
    if (a )
    {
        return a->occur;
    }
    return 0;
}

TArbre arbreFilsGauche(TArbre a){
    if (a )
    {
        return a->fg;
    }
    perror("Empty tree");
    exit(1);
}


TArbre arbreFilsDroit(TArbre a){
    if (a )
    {
        return a->fd;
    }
    perror("Empty tree");
    exit(1);
}