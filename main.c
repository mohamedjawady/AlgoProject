#include "dico/dico.h"
#include <sys/time.h>
#include "utils/utils.h"


#define MAX_WSIZE 100
#define TEST_SSIZE 5
#define DBG_SEED_VAL 10

int main(void)
{
    // seeding
    #ifndef MY_DEBUG
        struct timeval tv;
        gettimeofday(&tv,NULL);
        long long ms = (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
        srand(ms);
    #endif
    #ifdef MY_DEBUG
        srand(DBG_SEED_VAL);
    #endif
    TArbre dico = arbreConsVide();
    printf("Inserting words\n");
    char testCases[TEST_SSIZE][MAX_WSIZE] = {
            "gallon",
            "munier",
            "abenia",
            "mumu",
            "munier",
    };

    // Construct dictionary from testcases
    for (int i=0; i < TEST_SSIZE; i++){
        printf("Insertion step [%d/%d]: %s\n", i+1, TEST_SSIZE, testCases[i]);
        dicoInsererMot(testCases[i], &dico);
        char buffer[MAX_WSIZE+1];
        affichageRec(dico, buffer, 0);
    }

    printf("\nDisplaying occurrences of words\n");
    char occTest[TEST_SSIZE-1][MAX_WSIZE] = {
            "gallon",
            "munier",
            "abenia",
            "mumu",
    };
    for (int i=0; i < TEST_SSIZE; i++){
        printf("\"%s\"   \t, occurrences: %d\n", occTest[i], dicoNbOcc(occTest[i], dico));
    }

    char motpioche[MAX_WSIZE];
    printf("Inserting from file\n");
    for (int i = 0; i < 10; i++)
    {
        piocherMot(motpioche);
        dicoInsererMot(motpioche, &dico);
    }
    char buffer[MAX_WSIZE+1];
    printf("Displaying %d unique words from %d entries\n", dicoNbMotsDifferents(dico),dicoNbMotsTotal(dico) );
    affichageRec(dico, buffer, 0);

    // metadata of dictionary

    arbreSuppr(dico);



}
