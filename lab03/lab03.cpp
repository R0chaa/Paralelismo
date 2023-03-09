#include <iostream>

#define N 4

using namespace std

void conceito(int mediAluno){
	if (mediAluno < 4) cout << "O conceito do aluno foi 'E'";
	else if (mediAluno >= 4 && mediAluno < 6) cout << "O conceito do aluno foi 'D'";
	else if (mediAluno >= 6 && mediAluno < 7.5) cout << "O conceito do aluno foi 'C'");
	else if (mediAluno >= 7.5 && mediAluno < 9) cout << "O conceito do aluno foi 'B'";
	else if (mediAluno > 9) "O conceito do aluno foi 'A'";
}

int main(){
	int notas[N], mediAluno = 0;

	for(i=0; i<N; i++){
		cout << "Dige a nota " << i+1 << ": "
		cin >> notas[i];
	}

	mediAluno = (notas[0] + (notas[1]*2) + (notas[2]*3) + notas[3])/7;

	conceito(mediAluno);

	return 0;
}
