#include <stdio.h>

int acharLetra(char* palavra, char letra) {
	int index = -1;
	for (int i = 0; i < 32; i++) {
		if (palavra[i] != letra) continue;
		else index = i;
	}
	return index;
}

int main() {
	char palavra[32];
	char letra;

	printf("Digite uma palavra qualquer: ");
	scanf("%[^\n]s", &palavra);
	getchar();

	printf("\nDigite a letra que quer procurar na palavra: ");
	scanf("%c", &letra);

	if (acharLetra(&palavra, letra) != -1)
		printf("A letra foi encontrada no index %d da palavra.\n\n", acharLetra(&palavra, letra));
	else
		printf("A letra não foi encontrada! :(\n\n");

	return  0;
}
