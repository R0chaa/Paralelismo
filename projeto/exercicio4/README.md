# Exercício 04 - Decomposição de tarefas
### 1. Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.

![dagdafe](https://github.com/R0chaa/Paralelismo/assets/73042947/95cff0b5-0588-4767-890f-f99fcbb449cc)

```
1. Inicialização de variáveis
- Tarefa única
- Executa sequencialmente

2. Divisão do trabalho entre as threads
- Tarefa única
- Executa sequencialmente

3. Cálculo parcial da soma local
- Executada por cada thread
- Execução concorrente

4. Cálculo parcial do resultado inverso
- Executada por cada thread
- Execução concorrente

5. Cálculo da soma total
- Tarefa única
- Executa sequencialmente após a conclusão das tarefas 3 e 4

6. Cálculo do resultado final
- Tarefa única
- Executa sequencialmente após a conclusão da tarefa 5

7. Impressão do resultado final
- Tarefa única
- Executa sequencialmente após a conclusão da tarefa 6
```
### 2. Qual é o limite inferior do tempo de execução paralela para cada decomposição?
É possível escrever uma fórmula no modelo work-span para deduzir um limite inferior em Tp:
```
Maior valor entre:

Tp = (tempo serial / numero de processadors) => 0.231/2 = 0.1155
                               ou
Tp = se todos nós valem 1, soma a quantidade de nós do caminho crítico => 4

Limite inferior => 4
```
### 3. Quantos processadores são necessários para se conseguir o tempo mínimo de execução?
Para alcançar o tempo mínimo de execução, precisamos encontrar o valor de 'P' que minimiza o tempo de execução paralela, como o limite inferior do tempo de execução paralela é proporcional a 1/P, precisamos usar o máximo possível de processadores para alcançar o tempo mínimo de execução. 
No entanto, o número máximo de processadores que podem ser usados é limitado pelos recursos de hardware disponíveis.

### 4. Qual é o grau máximo de concorrência?
O grau máximo de concorrência é igual ao valor de thread_count (número de threads usadas na região paralela).

### 5. Qual é o paralelismo médio?
O grau médio de concorrência pode ser cálculado divindo o a quantidade de todos os nós pelo limite inferior do tempo de execução paralela para cada decomposição.
```
Paralelismo médio = 7/4 => 1.75
```
