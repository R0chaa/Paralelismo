#include <iostream>

#define N 5

using namespace std;

void imprime(int matriz[][N]){
	cout << "\n";
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << " " << matriz[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int matriz[N][N];
	int linha, x;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			matriz[i][j] = rand() % 10;
		}
	}

   	cout << "\nMatriz inicial:\n";
    	imprime(matriz);

    	//cout << "Qual linha você deseja multiplicar? ";
	//cin >> linha;
	linha = N-1;

    	//cout << "Digite o numero que você deseja multiplicar a linha " << linha+1 << ":";
    	//cin >> x;
	x = 2;

    	for(int j=0; j<N; j++){
        	matriz[linha-1][j] *= x;
    	}

    	cout << "\nMatriz resultante:\n";
    	imprime(matriz);
    
    	return 0;
}
