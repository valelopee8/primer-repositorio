#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

// Imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    double tiempo;
    struct timeval inicio, fin;
    gettimeofday(&inicio, NULL);

    if (argc != 3 || strcmp(argv[1], "-n") != 0) {
        printf("Uso: %s -n <tamaño_del_arreglo>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[2]);

    if (n <= 0) {
        printf("El tamaño del arreglo debe ser un número positivo.\n");
        return 1;
    }

    srand(time(nullptr));

    std::set<int> numeros;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        int num;
        do {
            num = rand() % (n + 1); 
        } while (numeros.count(num) > 0);
        arr[i] = num;
        numeros.insert(num);
    }

    //printf("Arreglo original:\n");
    //imprimirArreglo(arr, n);

    std::sort(arr, arr + n);

    //printf("Arreglo ordenado:\n");
    //imprimirArreglo(arr, n);

    delete[] arr;
    
    gettimeofday(&fin, NULL);
    tiempo = (fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec)/1000000.0;
    printf("Tiempo empleado: %g segundos\n", tiempo);

    return 0;
}
