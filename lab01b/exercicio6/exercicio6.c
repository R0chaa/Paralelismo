#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 2

int imprime(int** matriz){
	printf("\n");
	for(int i=0; i<LIN; i++){
		for(int j=0; j<COL; j++){
			printf("%d", matriz[i][j]);
		}
		printf("\n");
	}
}


int **transpor(int **ptr){
	int **transp = (int **)malloc(COL* sizeof(int*));

	for(int i=0; i<COL; i++)
		transp[i] = (int*) malloc(LIN*sizeof(int));

	for(int i=0; i<LIN; i++){
		for(int j=0; j<COL; j++) transp[j][i] = ptr[i][j];
	}

	return transp;
}

int main(){
	int **matriz = (int **)malloc(LIN*sizeof(int*));
	for(int i=0; i<LIN; i++) matriz[i] = (int *) malloc(COL * sizeof(int));

	for(int i=0; i<LIN; i++){
		for(int j=0; j<COL; j++){
			matriz[i][j] = rand() % 10;
		}
	}
	imprime(matriz);

	int **transposta = transpor(matriz);
	imprime(transposta);
}
