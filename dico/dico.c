#include "dico.h"

void affichageRec(TArbre a, char *str, short bufidx)
/* This function takes as input a TArbre and displays it.
 * The display mode is Postfix.
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
            affichageRec(a->fd, str, bufidx);
            str[bufidx++] = a->val;
            affichageRec(a->fg, str, bufidx);
        }
        else
        {
            affichageRec(a->fd, str, bufidx);
            str[bufidx++] = a->val;
            printf("%s\n", str);
        }
    }
}


void dicoInsererMot(char* word, TArbre *pa)
/* This function takes as input a pointer to TArbre and a word to insert.
 * Params:
 *  TArbre* ptr_a : Pointer to input tree.
 *  char*   word  : Word to insert.
 * Returns: VOID
 * */
{
    TArbre *ptr = pa;

    if (*ptr == NULL)
    {
        *pa = arbreCons(*word, 0, NULL, NULL);
        for (int i = 1; i < strlen(word); i++)
        {
            (*pa)->fg = arbreCons(word[i], 0, NULL, NULL);
            pa = &((*pa)->fg);
        }
        (*pa)->fg = arbreCons('\0', 1, NULL, NULL);
        return;
    }

    while ((*word >= (*ptr)->val))
    {
        if (*word == (*ptr)->val)
        {
            if (*word == '\0')
            {
                (*ptr)->occur++;
                return;
            }
            word++;
            pa = ptr;
            ptr = &((*ptr)->fg);
        }
        else
        {
            pa = ptr;
            ptr = &((*ptr)->fd);
        }
        if (*ptr == NULL)
        {
            break;
        }
    }

    if ((*pa)->fd == *ptr)
    {
        TArbre temp = (*pa)->fd;
        (*pa)->fd = arbreCons(*word, (*word == '\0') ? 1 : 0, NULL, temp);
    }
    else
    {
        if (*pa != *ptr)
        {
            TArbre temp = (*pa)->fg;
            (*pa)->fg = arbreCons(*word, (*word == '\0') ? 1 : 0, NULL, temp);
        }
        else
        {

            *pa = arbreCons(*word, 0, NULL, *ptr);
            ptr = pa;
        }
    }

    if (*word != '\0')
    {
        for (int i = 1; i < strlen(word); i++)
        {
            (*ptr)->fg = arbreCons(word[i], 0, NULL, NULL);
            ptr = &((*ptr)->fg);
        }
        (*ptr)->fg = arbreCons('\0', 1, NULL, NULL);
    }
}

int dicoNbOcc(char* word, TArbre a)
/* This function takes as input a TArbre and a string to return its occurrences.
 * Params:
 *  TArbre a : Input tree
 *  char *word: String to count its occurrence.
 * Returns: int -> number of occurences
 * */
{
    TArbre ptr = a;
    for (int i = 0; i <= strlen(word); i++)
    {
        if (ptr == NULL)
        {
            return 0;
        }

        if (ptr->val == word[i])
        {
            if (ptr->val == '\0')
            {
                return ptr->occur;
            }
            // le caractère est retenue donc on passe au fils gauche
            ptr = ptr->fg;
        }
        else
        {
            // le caractère est rejeté, on passe au fils droit
            ptr = ptr->fd;
            i--;
        }
    }
    return 0;
}

