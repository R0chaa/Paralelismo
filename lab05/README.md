# Lab05 - OpenMP

### Trapézio serial
Para compilar e executar o programa serial certifique-se que o gcc está instalado em sua máquina e então use o comando: "gcc trap-serial.c -o serial -fopenmp -lm" e em seguida abra o arquivo executável "serial" usando:

 ```
time ./serial
 ```

### Trapézio paralelo
Para compilar e executar o programa paralelo certifique-se que o gcc está instalado em sua máquina e então use o comando: "gcc trap-paralelo.c -o paralelo -fopenmp -lm" e em seguida abra o arquivo executável "paralelo" usando:

 ```
time ./paralelo <n-de-threads>"
 ```

# Comparações de Speed-up

**Média do tempo serial: 12.289s** 

Média do tempo paralelo com 2 threads: 9.914s
 ```
Speedup: 1.239
 ```

Média do tempo paralelo com 4 threads: 10.127s
 ```
Speedup: 1.213
 ```

Média do tempo paralelo com 8 threads: 10.129s
 ```
Speedup: 1.213
 ```
 
 > Para calculo da média de tempo os respectivos algoritmos foram executados 10 vezes.
