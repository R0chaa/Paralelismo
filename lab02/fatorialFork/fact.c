#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int num = 13, j;
	long long int i;
	pid_t pid;
	int fd[2];

	//printf("Digite um num: ");
	//scanf("%d", &num);

	if (pipe(fd) == -1) {
        	perror("pipe");
        	exit(EXIT_FAILURE);
    	}

    	pid = fork();

    	if (pid == -1) {
        	perror("fork");
        	exit(EXIT_FAILURE);
    	}

    	if (pid == 0) {
        	close(fd[0]); 
        	j = num;
        	for (i = 1; j > 1; j--) i = i * j;

        	write(fd[1], &i, sizeof(i));
        	close(fd[1]);
        	exit(EXIT_SUCCESS);

    	} else {
	        close(fd[1]);
	        wait(NULL);
        	long long int result;
        	read(fd[0], &result, sizeof(result));
        	close(fd[0]);
        	printf("O fatorial de %d é %lld\n", num, result);
    	}
    	return 0;
}
