#include <stdlib.h> 
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printWinners(TuringWinner *Winner, int nombreGagnants) {
    printf("%i\n", nombreGagnants);
    for (int i = 0; i < nombreGagnants; i++) {
        printf("%i\n", Winner[i].annee);
        printf("%s\n", Winner[i].nom);
        printf("%s\n", Winner[i].commentaire);
    }
}
void readWinners(TuringWinner **Winner, int nombreGagnants) {
    *Winner = (TuringWinner )calloc(nombreGagnants, sizeof(TuringWinner));
    for (int i = 0; i < nombreGagnants; i++) {
        (Winner)[i].annee = scanLineAsInt();
        (Winner)[i].nom = scanLine();
        (Winner)[i].commentaire = scanLine();
    }
}

int main(void) {
    int nbGagnants = scanLineAsInt();
    TuringWinner *Winner;
    readWinners(&Winner, nbGagnants);
    printWinners(Winner, nbGagnants);
    free(Winner);
    return EXIT_SUCCESS;
}
