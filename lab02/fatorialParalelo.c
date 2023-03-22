#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
pip[0] - the read end of the pipe - is a file descriptor used to read from the pipe
pip[1] - the write end of the pipe - is a file descriptor used to write to the pipe 

http://www2.cs.uregina.ca/~hamilton/courses/330/notes/unix/pipes/pipes.html
*/

int main(){
	int num, j, pid, pip[2];
	long long int result, i; //Como a saida do fatorial se torna estupidamente grande e utilizamos i para calcular, ambos devem ser do tipo long long int

	printf(" Digite um num: ");
	scanf("%d", &num);

	pipe(pip); // Se o pipe não foi criado com sucesso o programa é encerrado

	pid = fork(); // Cria um processo filho

	if (pid == -1) { //Checa se o processo filho foi criado com sucesso, senão encerra o programa
    	perror("fork");
    	exit(EXIT_FAILURE);
	}

	if (pid == 0) { // Se o processo criado com sucesso for o filho
    	close(pip[0]);
    	j = num;

    	for (i = 1; j > 1; j--)
    	    i *= j; // Calcula o fatorial de "num"

    	write(pip[1], &i, sizeof(i)); // O resultado é escrito em pip[1]
    	close(pip[1]);
    	exit(EXIT_SUCCESS);

	} else { // Se o processo criado com sucesso for o pai
        close(pip[1]); // Fecha pip[1]
        wait(NULL); // Aguarda o encerramento do processo filho

    	read(pip[0], &result, sizeof(result)); // Processo pai lê o resultado do fatorial e o armazena em 'result'
    	close(pip[0]); // Fecha pip[0]
    	printf(" > O fatorial de %d é %lld\n", num, result); //Exibe na tela o resultado do fatorial
    }
    return 0;
}

