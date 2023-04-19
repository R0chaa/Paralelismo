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
	int num = 6, j, pid1, pid2, pip1[2], pip2[2]; // pip1 e pip2 serão utilizados para a comunicação dos processos filhos e pid1 e pid2 para a comunicação dos processos
    	long long int result1=1, result2=1, i; //Como a saida do fatorial se torna estupidamente grande e utilizamos i para calcular, ambos devem ser do tipo long long int

   	//printf("Digite um num: ");
    	//scanf("%d", &num);

    	pipe(pip1); // Se o pipe 1 não foi criado com sucesso o programa é encerrado
    	pipe(pip2); // Se o pipe 2 não foi criado com sucesso o programa é encerrado

    	pid1 = fork(); // Cria um processo filho

    	if (pid1 == -1) { // Checa se o processo filho foi criado com sucesso, senão encerra o programa
        	perror("fork");
        	exit(EXIT_FAILURE);
    	}

    	if (pid1 == 0) { // Se o processo criado com sucesso for o filho
        	close(pip1[0]); // Fecha o descritor de leitura de pip1
        	j = num / 2;

        	for (i = 1; i <= j; i++) {
            		result1 *= i; // Calcula o fatorial pra primeira metade de "num"
			sleep(1);
		}

        	write(pip1[1], &result1, sizeof(result1));  //Escreve o resultado da primeira metade em "result1"
        	close(pip1[1]); // Fecha o descritor de escrita de pip1
        	exit(EXIT_SUCCESS);

    	} else { // Se o processo criado com sucesso for o pai
        	pid2 = fork(); // Cria o segundo processo filho

        	if (pid2 == -1) { // Checa se o segundo processo filho foi criado com sucesso, senão encerra o programa
            		perror("fork");
            		exit(EXIT_FAILURE);
        	}

        	if (pid2 == 0) { // Se o processo criado com sucesso for o segundo filho, o utiliza para calcular a segunda parte do fatorial de 'num'
            		close(pip2[0]); // Fecha o descritor de leitura de pip2
            		j = num; 

            		for (i = (num / 2) + 1; i <= j; i++) { 
                		result2 *= i; // Calcula o fatorial pra segunda metade de "num"
            			sleep(1);
			}

            		write(pip2[1], &result2, sizeof(result2)); // Escreve o resultado da segunda metade em "result2"
            		close(pip2[1]); // Fecha o descritor de escrita de pip1
            		exit(EXIT_SUCCESS);

        	} else { // Volta ao processo pai
            		close(pip1[1]); // Fecha o descritor de escrita de pip1
            		close(pip2[1]); // Fecha o descritor de escrita de pip2
            		wait(NULL); // Aguarda os processos filhos
            		wait(NULL); // Aguarda os processos filhos

            		read(pip1[0], &result1, sizeof(result1)); // Lê o retorno do processo filho pip1 e armazena o resultado em result1 (que contêm a primeira metade do fatorial de "num")
            		read(pip2[0], &result2, sizeof(result2)); // Lê o retorno do segundo processo filho pip2 e armazena o resultado em result2 (que contêm a segunda metade do fatorial de "num")
            		printf("Fatorial de %d: %lld\n", num, result1 * result2);

            		close(pip1[0]); //Fecha o descritor de leitura
            		close(pip2[0]); //Fecha o descritor de leitura
            		exit(EXIT_SUCCESS);
        	}
    	}
    	return 0;
}
