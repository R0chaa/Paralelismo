#include <stdio.h>

long double factorial(int n){
  if(n == 0) return 1;
  return n * (factorial(n - 1));
}


long double euler(long double *e, int n){
  int i = 0;
  for(i = 0; i < n; i++){
    *e += (1/factorial(i));
  }
  return *e;
}

int main() {
  long double e = 0.0;
  printf("Euler: %.18Lf", euler(&e, 20));
  
  return 0;
}
