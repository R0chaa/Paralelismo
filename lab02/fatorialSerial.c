#include <stdio.h>
#include <unistd.h>

//Fatorial serial cedido pelo professor para que realizamos as alterações

int main(){
   	int i, num = 6, j;

   	//printf ("Enter the number: ");
   	//scanf ("%d", &num);

   	j = num;

   	for (i=1; j > 1; j = j -1){
		i=i*j;
		sleep(1);
	}

   	printf("The factorial of %d is %d\n", num, i);
	return 0;
}
