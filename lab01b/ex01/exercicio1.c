#include <stdio.h>
#include <stdlib.h>

#define N 3

void imprime(int matriz[N][N]){
	int i = 0, j = 0;

    	printf("\nMatriz: \n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}
}

int encontraMaior(int matriz[N][N]){
	int maior = 0, linha = 0, i, j;

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(matriz[i][j] > maior){
				maior = matriz[i][j];
				linha = i;
			}
		}
	}

	return linha;
}

int main(){
	int matriz[N][N], i, j;
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			matriz[i][j] = rand() % 10;
		}
	}

	imprime(matriz);
	printf("\n > O maior número esta localizado na linha %d\n", encontraMaior(matriz) + 1);
	return 0;
}
