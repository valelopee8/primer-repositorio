#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

// Verificar si un número es primo
bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Generar los primeros n números primos
void generarPrimos(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (esPrimo(num)) {
            // printf("%d ", num);
            count++;
        }
        num++;
    }
    // printf("\n");
}

int main(int argc, char* argv[]) {
    double tiempo;
    struct timeval inicio, fin;
    gettimeofday(&inicio, NULL);
    
    if (argc != 3 || strcmp(argv[1], "-n") != 0) {
        printf("Uso: %s -n <cantidad_de_primos>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[2]);
    // printf("Los primeros %d números primos son:\n", n);
    generarPrimos(n);
    
    gettimeofday(&fin, NULL);
    tiempo = (fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    printf("Tiempo empleado: %g segundos\n", tiempo);

    return 0;
}
