#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Trap(double a, double b, int n);

double f(double x);

int main(int argc, char* argv[]){;
        double global_result;
	double a = 0.0, b = 100.0;
        int n = 1000000000;

        printf("Enter a, b, and n\n");
        scanf("%lf %lf %d", &a, &b, &n);

        global_result = Trap(a, b, n);

        printf("With n = %d trapezoids, our estimate\n", n);
        printf("of the integral from %f to %f = %.14e\n", a, b, global_result);

        return 0;
}

double Trap(double a, double b, int n)
{
	int i = 0;
	double h, approx, x_i;

	h = (b-a)/n;
	approx = (f(a) + f(b))/2.0;

	for(i = 1; i <= n-1; i++){
		x_i = a + i*h;
		approx += f(x_i);
	}

	approx *= approx;
	return approx;
}

double f(double x){
        return exp(x);
}
