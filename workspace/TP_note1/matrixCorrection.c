// gcc --std=c99 -Wall matrixCorrection.c -o prog
// ./prog < matrices.txt > out.txt
// diff matrices.txt out.txt

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prog < matrices.txt > out.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned short lines;
	unsigned short columns;
	int **values;
} Matrix;

typedef struct {
	unsigned short length;
	Matrix *matrix;
} MatrixArray;

void readMatrix(Matrix *m)
{
	scanf("%hi %hi", &m->lines, &m->columns);
	m->values = calloc(m->lines,sizeof(int *));

	for(int l=0; l<m->lines; l++){
		m->values[l] = calloc(m->columns,sizeof(int));
		for(int c=0; c<m->columns; c++){
			scanf("%i ",&m->values[l][c]);
		}
	}
}

void freeMatrix(Matrix *m) {
	for(int l=0; l<m->lines; l++){
		free(m->values[l]);
		m->values[l] = NULL;
	}
	free(m->values);
	m->values = NULL;
}

void readMatrixArray(MatrixArray matrixArray) {
	for(int i = 0; i < matrixArray.length; i++) {
		readMatrix(&matrixArray.matrix[i]);
	}
}

void printMatrix(Matrix *m)
{
	printf("%i %i\n",m->lines, m->columns);
	for(int l=0; l<m->lines; l++){
		for(int c=0; c<m->columns; c++){
			if(c!=0) printf(" ");
			printf("%i",m->values[l][c]);
		}
		printf("\n");
	}
}

void printMatrixArray(MatrixArray matrixArray) {
	printf("%i\n",matrixArray.length);
	for(int i = 0; i < matrixArray.length; i++) {
		printMatrix(&matrixArray.matrix[i]);
	}
}

void freeMatrixArray(MatrixArray *matrixArray) {
	for(int i = 0; i < matrixArray->length; ++i) {
		freeMatrix(&matrixArray->matrix[i]);
	}
	free(matrixArray->matrix);
	matrixArray->matrix = NULL;
}

void rotate90ccwMatrix(Matrix *in, Matrix *out) {
	out->lines = in->columns;
	out->columns = in->lines;
	out->values = calloc(out->lines,sizeof(int *));

	int line = 0;
	int col = in->columns-1;

	for(int l=0; l<out->lines; l++){
		out->values[l] = calloc(out->columns,sizeof(int));
		for(int c=0; c<out->columns; c++){
			out->values[l][c] = in->values[line][col];

			line = line+1;
			if(line>=in->lines) {
				line = 0;
				col = col-1;
				if(col<0)
					col = 0;
			}
		}
	}
}

MatrixArray *rotate90ccw(MatrixArray *matrixArray) {
	MatrixArray *res = malloc(sizeof(MatrixArray));
	res->length = matrixArray->length;
	res->matrix = calloc(res->length,sizeof(Matrix));

	for(int i = 0; i < matrixArray->length; ++i) {
		rotate90ccwMatrix(&matrixArray->matrix[i],&res->matrix[i]);
	}

	return res;
}

int main(void)
{
	MatrixArray matrixArray;
	scanf("%hi",&matrixArray.length);
	matrixArray.matrix = calloc(matrixArray.length,sizeof(Matrix));

	readMatrixArray(matrixArray);
	// printMatrixArray(matrixArray);

	MatrixArray *rotated = rotate90ccw(&matrixArray);
	printMatrixArray(*rotated);
	freeMatrixArray(rotated);
	free(rotated);

	freeMatrixArray(&matrixArray);

	return EXIT_SUCCESS;
}
