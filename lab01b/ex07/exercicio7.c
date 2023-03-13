#include <stdio.h>
#include <string.h> //biblioteca para string C e C++

typedef struct {
	char nome[32];
	int idade;
	float peso;
	float altura;
} Pessoa;

int main() {

	Pessoa grupo[] = { {"Damasceno", 23, 50.0f, 1.80f}, {"Rocha", 21, 48.0f, 2.00f}, {"Son Goku", 30, 62.0f, 1.75f}, {"Pikachu", 10, 8.0f, 0.94f}};
	char primeiroNome[32], segundoNome[32], terceiroNome[32];
	int x = 0, i = 0;  //o x determina que nome estamos procurando

	printf("Digite o nome da primeira pessoa: ");
	scanf("%[^\n]s", &primeiroNome);
	getchar();

	printf("Digite o nome da segunda pessoa: ");
	scanf("%[^\n]s", &segundoNome);
	getchar();

	printf("Digite o nome da terceira pessoa: ");
	scanf("%[^\n]s", &terceiroNome);

	while (i < 32) { // condição de parada
		for (i = 0; i < 32; i++) { // resetar a condição de parada para cada procura
			if (x == 0) {
				if (strcmp(grupo[i].nome, primeiroNome) == 0) {
					printf("\nNome: %s\nIdade: %d\nPeso: %.2f\nAltura: %.2f\n\n", grupo[i].nome, grupo[i].idade, grupo[i].peso, grupo[i].altura);
					x++;
					break;
				}
				else continue;
			}
			else if (x == 1) {
				if (strcmp(grupo[i].nome, segundoNome) == 0) {
					printf("Nome: %s\nIdade: %d\nPeso: %.2f\nAltura: %.2f\n\n", grupo[i].nome, grupo[i].idade, grupo[i].peso, grupo[i].altura);
					x++;
					break;
				}
				else continue;
			}
			else if (x == 2) {
				if (strcmp(grupo[i].nome, terceiroNome) == 0) {
					printf("Nome: %s\nIdade: %d\nPeso: %.2f\nAltura: %.2f\n\n", grupo[i].nome, grupo[i].idade, grupo[i].peso, grupo[i].altura);
					x++;
					break;
				}
				else continue;
			}
		}
	}
}
