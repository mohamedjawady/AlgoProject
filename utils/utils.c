#include "utils.h"


int nombreAleatoire(int nombreMax)
/* Generates a random number within the boundaries of [0, numbreMax] */
{
    return (rand() % nombreMax);
}

int piocherMot(char *motPioche)
/* Selects a random word from dico.txt and stores it in a char* */
{
    FILE *dico = NULL;
    int nombreMots = 0, numMotChoisi = 0;
    int readChar = 0;
    dico = fopen("../dico.txt", "r");

    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0;
    }
    do
    {
        readChar = fgetc(dico);
        if (readChar == '\n')
            nombreMots++;
    } while (readChar != EOF);

    numMotChoisi = nombreAleatoire(nombreMots);
    rewind(dico);
    while (numMotChoisi > 0)
    {
        readChar = fgetc(dico);
        if (readChar == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico);

    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1;
}