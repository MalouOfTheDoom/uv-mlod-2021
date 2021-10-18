#include <stdlib.h> 
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct structMatrix {
    int nbLignes;
    int nbCol;
    int *tab; //tableau[][] dont la taille est à determiner dynamiquement.
} Matrix;

typedef struct structMatrixArray {
    int nbMatrices;
    Matrix *matrices; //tableau[] dont la taille est à determiner dynamiquement.
} MatrixArray;

void readMatrix(Matrix matrix){
    //a completer
}

void readMatrixArray(MatrixArray *matrixArray){
    
    int nbDeMatrices;
    scanf("%u \n", &nbDeMatrices); //on recupère le nombre de matrices

    for(int i=0; i < nbDeMatrices; i++) {
        int nbLignes, nbCol;
        scanf("%u %u", &nbLignes, &nbCol); //on recupère le nombre de lignes/colonnes de la matrice en cours de lecture.
        Matrix matrix;
        readMatrix(matrix);
        //a completer
    }
}

void printMatrix(Matrix matrix){
    for(int col =0; col < matrix.nbCol; col++;){
        //a completer
    }
}

void printMatrixArray(MatrixArray matrixArray) {
    for(int i=0; i< matrixArray.nbMatrices; i++) {
        //a completer
    }
}

int main(void){

    MatrixArray matrixArray;
    readMatrixArray(&matrixArray);

    return EXIT_SUCCESS;
}