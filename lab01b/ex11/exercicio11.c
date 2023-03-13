#include <stdio.h>
#define rows 3
#define cols 4


void printMatriz(int* matriz) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", *(matriz + i * cols + j));
		}
		printf("\n");
	}
}

int* somarL1L2(int* matriz) { //Somar linha 1 e linha 2 e colocar resultados na linha 2.
	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < cols; j++) {
			*(matriz + i * cols + j) = *(matriz + i * cols + j)  + *(matriz + 0 * cols + j);
		}
		printf("\n");
	}
	return matriz;
}

int* multL1L2(int* matriz) { //Somar linha 1 e linha 2 e colocar resultados na linha 2.
	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < cols; j++) {
			*(matriz + i * cols + j) = *(matriz + i * cols + j) * *(matriz + 0 * cols + j);
		}
		printf("\n");
	}
	return matriz;
}


int main() {
	
	int matriz[rows][cols] = {
		{10,9,8,7},
		{12,32,50,1},
		{88,21,112,4}
	};

	printf("Matriz original: \n\n");
	printMatriz(&matriz[0][0]);

	int* matrizResultado;
	printf("\nApos somar L1 com L2 e salvando em L2: \n");
	matrizResultado = somarL1L2(&matriz[0][0]);
	printMatriz(matrizResultado);

	printf("\nApos multiplicar L1 com L2 e salvando em L2: \n");
	matrizResultado = multL1L2(&matriz[0][0]);
	printMatriz(matrizResultado);

	return 0;
}
