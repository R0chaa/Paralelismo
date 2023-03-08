#include <iostream>
#include <cstdlib>

#define N 3

using namespace std;

void imprime(int matriz[][]){
	for(int i=0; i<N; i++){
		cout << endl;
		for(int j=0; i<N; i++){
			cout << matriz[i][j];
		}
	}
}

int encontraMaior(int matriz [][]){
	int maior = 0, linha;

	for(int i=0; i<N; i++){
		for(int j=0; i<N; j++){
			if(matriz[i][j] > maior){
				maior = matriz[i][j];
				linha = i;
			}
		}
	}

	return linha;
}

int main(){
	int matriz[N][N];
	
	srand(9);
	for(int i=0; i<N; i++){
		for(int j=0; i<N; i++){
			matriz[i][j] = rand();
		}
	}

	imprime(matriz[N][N]);
	cout << "\n\n > O maior número esta localizado na linha " << i+1;
	return 0;
}
