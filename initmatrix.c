#include <time.h>
#include <stdlib.h>
#include <stdio.h>



void generateRandomMatrix(int **matrix, int dim){
	srand(time(0));
	int i, j;
	for (i = 0; i < dim; ++i) {
		for (j = 0; j < dim; ++j) {
			matrix[i][j] = (rand() % (99 - 0 + 1)) + 0;
		}
	}

}

