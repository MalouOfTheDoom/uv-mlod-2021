#include <stdlib.h> 
#include <stdint.h>
#include <stdio.h>

float calculPrix(float prix_plein_tarif, unsigned int age_enfant) {
        if (age_enfant <= 2){
            return 0.1 * prix_plein_tarif;
        }
        if (age_enfant <= 12) {
            return 0.5 * prix_plein_tarif;
        }
        return prix_plein_tarif;
}

void des(int N){ //N doit être compris entre 3 et 18
    for (int d1=1; d1<=6; d1++){
        for (int d2=1; d2<=6; d2++){
            for (int d3=1; d3<=6; d3++){
                if(d1+d2+d3 == N){
                    printf("%i %i %i \n", d1,d2,d3);
                }
            }
        }
    }
}

int isParfait(N){
    int somme_diviseurs = 0;
    for (int diviseur_potentiel = 1; diviseur_potentiel < N; diviseur_potentiel++) {
        if (isDiviseur(diviseur_potentiel, N)){
            somme_diviseurs += diviseur_potentiel;
        }
    }
    if(somme_diviseurs == N) {
        return 0;
    }
    return 1;
}

int isDiviseur(a,b){
    if (a%b == 0){
        return 0;
    }
    else { return 1; }
}

int main(void){

    /*
    float prix_plein_tarif =15.0;
    unsigned int age = 4;
    printf("%f \n",calculPrix(prix_plein_tarif, age));
    */

    //des(4);

    int N = 6;
    int isParfait(N);


    return EXIT_SUCCESS;
}