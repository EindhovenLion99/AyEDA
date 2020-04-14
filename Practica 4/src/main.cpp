#include <iostream>
#include "Tabla.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    cout << endl;
    cout << "************** Practica 4 *************" << endl;

    int Tabla_sz, Celdas_sz, factor;

    cout << "Introduce el tamaño de la tabla: ";
    cin >> Tabla_sz;
    cout << "Introduce el numero de celdas: ";
    cin >> Celdas_sz;
    cout << "Introduce el factor: ";
    cin >> factor;

    // Creando banco de pruebas:

    srand(time(NULL));

    int N = Tabla_sz * Celdas_sz * factor;

    int *array = new int[N];
    for (int i = 0; i < N; i++)
    {
        unsigned long x = rand() % 99999999;
        array[i] = x;
    }

    for (int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Creando una Tabla Hash" << endl;

    Tabla<int> tabla_int(10, 3, 2, 1);
}