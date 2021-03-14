#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "initmatrix.h"
#include "calculmatrix.h"
#include "allocation.h"


#include <mpi.h>





int main(int argc, char *argv[])
{
     MPI_Init(&argc, &argv);
    int n=4;
    int **A,**B,**C,**D;
    int size,rank;

   
  
    A = (int **)malloc(n * sizeof(int *));
	    for (int i = 0; i < n; i++){
		A[i] = (int *)malloc(n * sizeof(int));}

        B = (int **)malloc(n * sizeof(int *));
	    for (int i = 0; i < n; i++){
		B[i] = (int *)malloc(n * sizeof(int));}

        C = (int **)malloc(n * sizeof(int *));
	    for (int i = 0; i < n; i++){
		C[i] = (int *)malloc(n * sizeof(int));}
  //  allc(B,n);
   // allc(C,n);
   // allc(D,n);

    
  generateRandomMatrix(A, n);
    generateRandomMatrix(B, n);
    
    
    
    affiche_matrix(A,n);
    //affiche_matrix(B,n);
    


   
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    n=atoi(argv[1]);

    if(rank!=0){MPI_Recv(C,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);}
  work(rank,A,B,C,n,size);
    if(rank!=n-1){
    MPI_Send(C,1,MPI_INT,rank+1,0,MPI_COMM_WORLD);}
    
    
   
    //printf("Hello world\n"); 
    MPI_Finalize();
         


 exit(0);


}