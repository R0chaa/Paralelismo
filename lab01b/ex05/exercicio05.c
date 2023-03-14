#include <stdio.h>
#include <stdlib.h>

#define N 5

void imprime(int matriz[N][N]){
	int i = 0, j = 0;

	printf("\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	int matriz[N][N];
	int linha, x, i, j;

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			matriz[i][j] = rand() % 10;
		}
	}

   	printf("\nMatriz inicial:\n");
    	imprime(matriz);

	//cout << "Qual linha você deseja multiplicar? ";
	//cin >> linha;
	linha = N-1;

    	//cout << "Digite o numero que você deseja multiplicar a linha " << linha+1 << ":";
    	//cin >> x;
	x = 2;

    	for(j=0; j<N; j++){
    		matriz[linha-1][j] *= x;
    	}

    	printf("\nMatriz resultante:\n");
    	imprime(matriz);

	return 0;
}
