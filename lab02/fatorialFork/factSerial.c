# include <stdio.h>


int main()

{

   int i, num=13, j;

   //printf ("Enter the number: ");

   //scanf ("%d", &num);

   j = num;


   for (i=1; j > 1; j = j -1) {

         i=i*j;

   }


   printf("The factorial of %d is %d\n",num,i);

}
