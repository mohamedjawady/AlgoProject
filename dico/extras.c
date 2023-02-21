#include "dico.h"

void affichageRecInf(TArbre a, char *str, short bufidx)
/* This function takes as input a TArbre and displays it.
 * The display mode is Infix.
 * Params:
 *  TArbre a : Input tree
 *  char *str: buffer to construct output string
 *  short bufidx: advancement placeholder, to be intialized to 0
 * Returns: VOID
 * */
{
    if (!(arbreEstVide(a)))
    {
        if ((a->val != '\0'))
        {
            char temp[100];
            for (int i = 0; i < bufidx; i++)
            {
                temp[i] = str[i];
            }
            temp[bufidx] = a->val;
            affichageRecInf(a->fg, temp, bufidx+1);
            affichageRecInf(a->fd, str, bufidx);
        }
        else
        {
            for (int i = 0; i < bufidx; i++)
            {
                printf("%c", str[i]);
            }
            printf("\n");
            affichageRecInf(a->fd, str, bufidx);
        }
    }
}



int dicoNbMotsDifferents(TArbre a)
/* This function takes as input a TArbre and returns unique words count.
 * Params:
 *  TArbre a : Input tree
 * Returns: int -> number of unique words.
 * ** Warning: ** AVOID USING FOR LARGE LEVELS OF REPRESENTATIONS TO NOT EXCEED STACK LIMIT.
 * */
{
    if (a )
    {
        int endOfWord = 0;
        if(a->val == '\0'){
            endOfWord = 1;
        }
        return endOfWord + dicoNbMotsDifferents(a->fd) + dicoNbMotsDifferents(a->fg);
    }
    else
    {
        return 0;
    }
}

int dicoNbMotsTotal(TArbre a)
/* This function takes as input a TArbre and returns words count.
 * Params:
 *  TArbre a : Input tree
 * Returns: int -> number of words.
 * ** Warning: ** AVOID USING FOR LARGE LEVELS OF REPRESENTATIONS TO NOT EXCEED STACK LIMIT.
 * */
{
    if (a )
    {
        return a->occur + dicoNbMotsTotal(a->fd) + dicoNbMotsTotal(a->fg);
    }
    return 0;
}
