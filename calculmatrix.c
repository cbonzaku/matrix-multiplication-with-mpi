#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int caculElement(int i,int j,int **A,int **B,int n){
      int s=0;
    for (int k = 0; k < n; k++)
    {
      
        s=s+ A[i][k]*B[k][j];
    }
    return   s;
} 

void work(int id,int **A,int **B,int **C,int n,int nbr_prosses){
    int r= n/nbr_prosses;
    int istart=r*id;
    int ifin=istart+r;
                                                                                                                                                                                                                                                                                                                                                                                                        
    for (int i = istart; i < ifin; i++)
    {
       for (int j = istart; j < ifin; j++)
       {
           C[i][j]=caculElement(i,j,A,B,n);
       }
       
    }
    

}