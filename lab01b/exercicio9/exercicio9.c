// 9 Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.

#include <stdio.h>
#include <stdlib.h>

#define LIN 3;
#define COL 3;

void imprime(int matriz[LIN][COL]){
	for(int i = 0; i < LIN; i++){
    		for(int j = 0; j < COL; j++) printf("%d ", matriz[i][j]);
  		printf("\n");
	}
}

void substituir(int matriz[LIN][COL]){
  	for(int i=0; i < LIN; i++){
    		for(int j=0; j < COL; j++){
      			if(matriz[i][j] < 0) matriz[i][j] *= -1;
    		}
  	}
}

int main(){
  	int matriz[LIN][COL];

	for(int i=0; i<LIN; i++){
		for(int j=0; j<COL; j++){
			matriz[i][j] = rand() % 10;
		}
	}

  	substituir(matriz);
  	imprime(matriz);
  	return 0;
}
