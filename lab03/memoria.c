#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t childpid;
    
    int shmid;
    
    shmid = shmget (IPC_PRIVATE, sizeof (int), 0666|IPC_CREAT);
    
    int *ipcPointer = (int *) shmat (shmid, 0, 0);
    *ipcPointer = 1;
       
     if ((childpid = fork()) == 0)
    {
        printf("Valor inicial: %i\n", *ipcPointer);
        printf ("ID Filho após fork: %d\n", getpid());
        
        *ipcPointer += 2;
        printf("Valor após soma: %i\n", *ipcPointer);
    } 
    else
    {
        wait(NULL);
        *ipcPointer *= 4;
        printf("Valor multiplicado por 4 após soma do filho: %i\n", *ipcPointer);
    }

    return 0;
}
