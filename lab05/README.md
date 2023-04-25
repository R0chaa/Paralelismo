# Lab03 - OpenMP
Compilação e execução
Para compilar e executar o programa serial certifique-se que o gcc está instalado em sua máquina e então use o comando: "gcc trap-serial.c -o serial -fopenmp -lm" e em seguida abra o arquivo executável "serial" gerado na pasta do código fonte.

Para compilar e executar o programa paralelo certifique-se que o gcc está instalado em sua máquina e então use o comando: "gcc trap-paralelo.c -o serial -fopenmp -lm" e em seguida abra o arquivo executável "paralelo" gerado na pasta do código fonte.


# Comparações de Speed-up

Média do tempo serial: 0.093s

Média do tempo paralelo com 2 threads: 0.060s
 ```
Speedup: 1.55
 ```

Média do tempo paralelo com 4 threads: 0.052s
 ```
Speedup: 1.79
 ```

Média do tempo paralelo com 8 threads: 0.046s
 ```
Speedup: 2.02
 ```
 
 > Para calculo da média de tempo os respectivos algoritmos foram executados 10 vezes.
