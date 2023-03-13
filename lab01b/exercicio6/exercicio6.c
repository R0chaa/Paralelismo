#include <stdio.h>
#include <stdlib.h>

int LIN = 3, COL = 2;

int imprime(int** matriz){
	for(int i=0; i<LIN; i++){
		for(int j=0; j<COL; j++){
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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
	int aux;
	for(int i=0; i<LIN; i++) matriz[i] = (int *) malloc(COL * sizeof(int));

	for(int i=0; i<LIN; i++){
		for(int j=0; j<COL; j++){
			matriz[i][j] = rand() % 10;
		}
	}
	imprime(matriz);

	int **transposta = transpor(matriz);

	aux = LIN;
	LIN = COL;
	COL = aux;

	imprime(transposta);
}
