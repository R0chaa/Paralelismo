//13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.

#include <stdio.h>
#define N 100

void remover(char *str, int i){
	for (int j = i; j < N-1; j++) str[j] =  str[j+1];
}

int main(){
  	char str[N] = "sometimes it is the people no one can imagine anything of who do the things no one can imagine";
  	int i  = 21;

	printf(" > Entrada: %s\n", str);

  	remover(str, i);

  	printf(" > Saída: %s\n", str);

	return 0;
}
