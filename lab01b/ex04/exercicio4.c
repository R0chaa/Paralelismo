#include <stdio.h>
#include <string.h> //biblioteca para string C e C++


int alfabetoBool(char* primeiroNome, char* segundoNome) {
	for (int i = 0; i < 32; i++) {
		if (&primeiroNome[i] < &segundoNome[i]) {
			continue;
		}
		else return 0;
	}
	return 1;
}

int main() {
	char primeiroNome[32], segundoNome[32];

	printf("Escreva o primeiro nome: ");
	scanf("%[^\n]s", &primeiroNome);
	getchar();

	printf("Escreva o segundo nome: ");
	scanf("%s", &segundoNome);


	printf("Usando biblioteca string.h (C++)\n");
	if (strcmp(primeiroNome, segundoNome) < 0) {
		printf("%s\n%s", &primeiroNome, &segundoNome);
	} else {
		printf("%s\n%s", &segundoNome, &primeiroNome);
	}

	printf("\n\nUsando pointeiros (C)\n");
	if (alfabetoBool(*primeiroNome, *segundoNome)) { //Ponteiros para os vetores de char como parametros
		printf("%s\n%s", &primeiroNome, &segundoNome);
	}
	else {
		printf("%s\n%s", &segundoNome, &primeiroNome);
	}
	return 0;
}
