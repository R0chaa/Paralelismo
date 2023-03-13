#include <iostream>
#include <cstdlib>

#define N 3

using namespace std;

void imprime(int matriz[][N]){
    cout << "\nMatriz: \n";
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << " " << matriz[i][j];
		}
		cout << endl;
	}
}

int encontraMaior(int matriz[][N]){
	int maior = 0, linha = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
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
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			matriz[i][j] = rand() % 10;
		}
	}

	imprime(matriz);
	cout << "\n > O maior número esta localizado na linha " << encontraMaior(matriz) + 1 << endl;
	return 0;
}
