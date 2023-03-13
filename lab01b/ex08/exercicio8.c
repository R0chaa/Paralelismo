#include <stdio.h>

#define rows 3
#define cols 4

void gerarTransporta(int* matriz) {

	int temp[cols][rows] = {0};

	printf("Matriz original: \n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", *( matriz +i * cols + j));
			temp[j][i] = *(matriz + i * cols + j);
			//printf("i:%d\nj:%d\nValor: %d\n\n", i, j, *(matriz + i * cols + j));
		}
		printf("\n");
	}
	printf("\n\nTransporta gerada: \n");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			printf("%d ", temp[i][j]);
		}
		printf("\n");
	}
}

int main() {

	int matriz[rows][cols] = {
		{10,9,8,7},
		{12,32,50,1},
		{88,21,112,4}
	};

	gerarTransporta(&matriz[0][0]);

	return 0;

}
