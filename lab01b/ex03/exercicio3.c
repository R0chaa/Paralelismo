#include <stdio.h>

int main() {
	int x = 0, y = 0; //x -> tamanho da lista e numero maximo; y -> posicao inicial
	while (1) {
		printf("Escolha um número máximo impar: ");
		scanf("%d", &x);
		if (x % 2 != 0) {
			printf("\n");
			while (y != x) {
				for (int i = 0; i < y; i++) printf("  ");
				for (int j = 1 + y; j <= x - y; j++) {
					printf("%d ", j);
				}
				printf("\n");
				y++;
			}
			y = 0;
		}
		else printf("\nO número precisa ser impar... Tente novamente.\n");
	}
	return 0;
}
