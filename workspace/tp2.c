#include <stdlib.h> 
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void echangeContenu(int *a, int *b) {
    int temp_a = *a;
    *a = *b;
    *b = temp_a;
}

bool estConvexe(bool tab[],int length) {
    int nombreDeChaineTrue = 0;
    bool valPrecedente;
    for(int i = 1; i<length; i++) {
        valPrecedente = tab[i-1];
        if (tab[i] != valPrecedente){
            if (valPrecedente == true){
                nombreDeChaineTrue += 1;
            } 
        }
    }

    if (nombreDeChaineTrue>1) { return false; }
    return true;
}

void mult_matrice(int64_t matrice_res[5][5], int64_t matrice1[5][5], int64_t matrice2[5][5], int taille) {
    for(int i=0; i<taille; i++){
        for (int j=0; j<taille; j++){
            int64_t resultat_case = 0;
            for (int k=0; k<taille; k++) {
                resultat_case += matrice1[i][k] * matrice2[k][j];
            }
            matrice_res[i][j] = resultat_case;
        }
    }
}

void affiche_matrice(int64_t matrice[5][5], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("| ");
        for (int j = 0; j < taille; j++) {
            printf(" %lu ", matrice[i][j]);
        }
        printf(" | \n");
    }
    
};

typedef enum enumMois {janvier=1, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre} Mois;
typedef struct strucDate {
    int jour;
    Mois mois;
    int annee;
} Date;

void initialiseDate(Date *d) {
    printf("jour:");
    scanf("%u", &(d->jour));
    printf("mois:");
    scanf("%u", &(d->mois));
    printf("annee:");
    scanf("%u", &(d->annee));
}

// retourne la chaine de caractère représentant m
char* libelleMois(Mois m) {
    char *nomsDesMois[] = {"Janvier",
                           "Fevrier",
                           "Mars",
                           "Avril",
                           "Mai",
                           "Juin",
                           "Juillet",
                           "Août",
                           "Septembre",
                           "Octobre",
                           "Novembre",
                           "Décembre"};
    return nomsDesMois[m-1];
}

// retourne une date initialisée par copie
Date creerDateParCopie() {
	Date d;
	initialiseDate(&d);
	return d;
}

void afficheDate(Date* d){
    printf("%u %s %u \n", d->jour, libelleMois(d->mois), d->annee);
}

int main(void){

    //question 1 :
    /* int a=10, b=20;
    echangeContenu(&a, &b);
    printf("a = %u et b = %u \n", a, b); */

    //question 2 :
    /* bool tableau[] = {true, false, true, false, true, true};
    if (estConvexe(tableau, 6)){
        printf("le tableau est convexe \n");
    } else { printf("le tableau nest pas convexe \n"); } */

    //question 3 :
    /* int64_t matrice0[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];
    int taille = 5;
    mult_matrice(matriceResultat,matrice1,matrice2, taille);
    affiche_matrice(matrice0, 3); */

    //question 4 :
    

    Date d1;
    initialiseDate(&d1);
    afficheDate(&d1);

    Date d2 = creerDateParCopie();
    afficheDate(&d2);

    Date *date;
    date = newDate();
    afficheDate(date);
    //...
    free(date);




    return EXIT_SUCCESS;
}
