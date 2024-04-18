#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

const double epsilon = 1e-6; // Criterio de convergencia

// Función para leer la matriz y el vector desde un archivo
void leerDatos(const char* archivo, vector<vector<double>>& A, vector<double>& b) {
    ifstream entrada(archivo);
    if (!entrada) {
        cerr << "No se pudo abrir el archivo." << endl;
        exit(1);
    }

    int n;
    entrada >> n;

    A.resize(n, vector<double>(n));
    b.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            entrada >> A[i][j];
        }
        entrada >> b[i];
    }

    entrada.close();
}

// Función para imprimir el vector solución
void imprimirSolucion(const vector<double>& x) {
    cout << "La solucion aproximada es:" << endl;
    for (size_t i = 0; i < x.size(); ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

// Función para calcular el error relativo entre dos vectores
double errorRelativo(const vector<double>& x1, const vector<double>& x2) {
    double maxError = 0.0;
    for (size_t i = 0; i < x1.size(); ++i) {
        double error = abs((x1[i] - x2[i]) / x1[i]);
        if (error > maxError) {
            maxError = error;
        }
    }
    return maxError;
}

// Función para resolver el sistema de ecuaciones lineales usando el método de Jacobi
vector<double> jacobi(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    vector<double> x(n, 0.0); // Vector inicial de soluciones
    vector<double> x_ant(n);   // Vector para almacenar las soluciones anteriores

    int iteraciones = 0;
    do {
        x_ant = x; // Almacenar las soluciones anteriores

        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x_ant[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        iteraciones++;
    } while (errorRelativo(x, x_ant) > epsilon);

    cout << "Se alcanzó la convergencia en " << iteraciones << " iteraciones." << endl;

    return x;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <archivo>" << endl;
        return 1;
    }

    const char* archivo = argv[1];

    vector<vector<double>> A;
    vector<double> b;

    leerDatos(archivo, A, b);

    vector<double> solucion = jacobi(A, b);

    imprimirSolucion(solucion);

    return 0;
}

