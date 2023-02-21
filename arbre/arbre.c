#include "arbre.h"


TArbre arbreConsVide(void){
    /* This function constructs an empty TArbre.
 * Params:
 * Returns: TArbre.
     * */
    return (TArbre)NULL;
}


TArbre arbreCons(char c, int n, TArbre fg, TArbre fd){
/* This function takes as input two subtrees of TArbre and constructs a TArbre joined by a new node.
 * Params:
 *  TArbre fg, fd : Input subtree.
 *  char c: node character value.
 *  int n : occurence of word, defaulted to 0.
 * Returns: TArbre -> new TArbre.
 * */
    TArbre ptr = malloc(sizeof(Node));
    if (!ptr) {
        perror("malloc failed");
        exit(1);
    }
    ptr->occur = n;
    ptr->val = c;
    ptr->fg = fg;
    ptr->fd = fd;

    return ptr;
}

int arbreEstVide(TArbre a){
    /* State of Tree: empty or not*/
    return (a == NULL);
}

void arbreSuppr(TArbre a){
    if (a )
    {
        arbreSuppr(a->fg);
        arbreSuppr(a->fd);
        free(a);
    }    
}