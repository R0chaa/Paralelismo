#include <stdio.h>

void inserirLetra(char* palavra, char letra, int index) {
	palavra[index] = letra;
}

int main() {
	char palavra[100];
	char letra;
	int index;

	printf("Digite uma palavra qualquer: ");
	scanf("%[^\n]s", &palavra);
	getchar();

	printf("\nDigite a letra que quer inserir: ");
	scanf("%c", &letra);
	getchar();

	printf("\nDigite o index da palavra que quer mudar: ");
	scanf("%d", &index);

	inserirLetra(&palavra, letra, index);
	printf("\nPalavra atualizada: %s \n\n", &palavra);

	return  0;
}
