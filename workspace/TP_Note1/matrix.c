#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Matrix
{
	int nb_lignes;
	int nb_colonnes;
    int** values;
} Matrix;

typedef struct MatrixArray
{
	Matrix* matrices;
} MatrixArray;

Matrix readMatrix(){
    Matrix mat;
	mat = (Matrix)malloc(sizeof(Matrix));

	scanf("%i %i", &mat.nb_lignes, &mat.nb_colonnes);

	
	for(int i = 0; i < mat.nb_lignes; i++){
		for(int j = 0; j < mat.nb_colonnes; j++){
			scanf("%i", &mat.values[i][j]);
		}	
	}

	return mat;
}

MatrixArray* readMatrixArray(int nb_mat){
	MatrixArray* tab_mat;
	tab_mat = (MatrixArray*)malloc(nb_mat*sizeof(MatrixArray));

	for(int i = 0; i < nb_mat; i++){
		tab_mat->matrices[i] = readMatrix();
	}
	
}

void printMatrixArray(){
	
}

int nombre_matrices(){
	int buffer;
	scanf("%i\n",&buffer);
	return buffer;
}

int main()
{
	int nb_matrices = nombre_matrices();
	
	readMatrix();
	//readMatrixArray(nb_matrices);
	

	return EXIT_SUCCESS;
}