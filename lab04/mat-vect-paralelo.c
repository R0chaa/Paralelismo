#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int **A, *x, *y, m, n, thread_count;
//A: matriz, x: vetor, y: vetor resultante

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

void *pth_mat_vect(void* rank){
  long my_rank = (long) rank;
  int i,j;
  int local_m = m/thread_count;
  int my_first_row = my_rank+local_m-1; //-1 é uma alteração
  int my_last_row = (my_rank+1)+local_m-1;
  
  for(i = my_first_row; i <= my_last_row; i++){
      y[i] = 0.0;
      for(j = 0; j < n; j++){
          y[i] += A[i][j]*x[j];
      }
  }
  return NULL;
}


int main(int argc, char *argv[])
{
  int i, j;
  long tid; //id atual do thread

  m = 3; //atoi(argv[1]);
  n = 3; //atoi(argv[2]);
  thread_count = 2; //atoi(argv[3]);

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

  //alocando threads    
  pthread_t* threads;
  threads = (pthread_t *)malloc(thread_count * sizeof(pthread_t));

  //criando e fazendo join nas threads
  for(tid = 0; tid < thread_count; tid++){
      pthread_create(&threads[tid], NULL, pth_mat_vect, (void *)tid);
  }  
  for(tid = 0; tid < thread_count; tid++){
      pthread_join(threads[tid], NULL);
  }
  
  //print
  printf("\nMatriz A: \n");
  printMat(A, m,n);
  printf("\nVetor x: \n");
  printVect(x, n);
  printf("\nVetor resultado y: \n");
  printVect(y, m);
  
  //desaloca tudo
  free(threads);
  for(i = 0; i < m; i++){
      free(A[i]);
  }
  free(A);
  free(x);
  free(y);
  
  return 0;
}