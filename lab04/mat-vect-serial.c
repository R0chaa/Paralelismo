#include <stdlib.h>
#include <stdio.h>

int **A, *x, *y, m, n;
//A: matriz, x: vetor, Y: vetor resultante

void printMat(int **mat, int m , int n){
  int i, j;
  for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        printf("%d ", mat[i][j]);
      }
    printf("\n");
  }
}

void printVect(int *vect, int n){
  int i;
  for (i= 0; i < m; i++){
    printf("%d \n", vect[i]);
  }
  printf("\n");
}

void calc_mat_vect(){
  int i,j;
  for(i = 0; i < m; i++){
      y[i] = 0.0;
      for(j = 0; j < n; j++){
          y[i] += A[i][j]*x[j];
      }
  }
}

int main()
{
  int i, j;
  m = 3000; //numero de linhas da matriz
  n = 3000; //numero de colunas da matriz e tamanho do vetor

  //alocando matriz
  A = (int **)malloc(m * sizeof(int*));
  for(i = 0; i < m; i++) A[i] = (int *)malloc(n * sizeof(int));

  //alocando vetores
  x = (int *)malloc(n * sizeof(int));
  y = (int *)malloc(m * sizeof(int));
  
  //randomizar matriz e vetor
  for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
          A[i][j] = (i+j)*(i+2);
      }
  }
  for(j = 0; j < n; j++){
      x[j] = (i+j)*i;
  }

  //calcular multiplicacao
  calc_mat_vect();
  
  //print
  //printf("\nMatriz A: \n");
  //printMat(A, m,n);
  //printf("\nVetor x: \n");
  //printVect(x, n);
  //printf("\nVetor resultado y: \n");
  //printVect(y, m);
  
  //desaloca tudo
  for(i = 0; i < m; i++){
      free(A[i]);
  }
  free(A);
  free(x);
  free(y);
  
  return 0;
}
