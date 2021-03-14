#include <stdlib.h>
#include <stdio.h>


void allc(int **A,int n){
        A = (int **)malloc(n * sizeof(int *));
	    for (int i = 0; i < n; i++){
		A[i] = (int *)malloc(n * sizeof(int));}

}

void affiche_matrix(int **A, int n){
    printf("\n");
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
        {
            if(j==n-1){printf("-%d\n",A[i][j]);}
            else
            {
            printf("-%d-",A[i][j]);
            }
            
            

        }
     }
     printf("\n");

}