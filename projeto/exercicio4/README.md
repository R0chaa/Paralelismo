# Exercício 04 - Decomposição de tarefas
### 1. Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.
```
```
### 2. Qual é o limite inferior do tempo de execução paralela para cada decomposição?

É possível escrever uma fórmula no modelo work-span para deduzir um limite inferior em Tp:
```
Tp = tempo serial / numero de processadors => 0.231/2 = 0.1155
```
### 3. Quantos processadores são necessários para se conseguir o tempo mínimo de execução?

Para alcançar o tempo mínimo de execução, precisamos encontrar o valor de 'P' que minimiza o tempo de execução paralela, como o limite inferior do tempo de execução paralela é proporcional a 1/P, precisamos usar o máximo possível de processadores para alcançar o tempo mínimo de execução. 
No entanto, o número máximo de processadores que podem ser usados é limitado pelos recursos de hardware disponíveis.

### 4. Qual é o grau máximo de concorrência?
O grau máximo de concorrência é igual ao valor de thread_count (número de threads usadas na região paralela).

### 5. Qual é o paralelismo médio?
O paralelismo médio é igual à razão entre o tempo de execução paralela e o tempo de execução serial (tempo serial/ tempo paralelo), sendo igual a: 4.0526.
