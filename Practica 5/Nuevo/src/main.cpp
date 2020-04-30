#include <iostream>
#include <vector>
#include <iomanip>
#include "DNI.hpp"
#include "Insercion.hpp"
#include "Burbuja.hpp"
#include "Heap.hpp"
#include "Quick.hpp"
#include "Shell.hpp"
#include "Contador.hpp"
#include "termcolor.hpp"
#include "ISBN.hpp"

Contador ISBN::Cont_;

using namespace termcolor;

void Print_Array(vector<ISBN> &V, bool sorted);
void Filling(vector<ISBN> &V);
void Continue();

int main()
{
    bool sorted = false;
    int opc, pruebas, N, c;

    std::cout << yellow << "Introduce tamaño del vector: " << white;
    std::cin >> N;
    std::cout << yellow << "Introduce número de pruebas: " << white;
    std::cin >> pruebas;

    std::cout << endl;

    std::vector<ISBN> Array;
    Array.resize(N);

    std::cout << std::endl;

    for (int i = 0; i < pruebas; i++)
    {
        std::cout << "A continuacion se mostraran las trazas de cada algoritmo y las comparaciones realizadas:" << std::endl
                  << std::endl;

        Continue();
        int y = getchar();

        ISBN::Cont_.start();

        Filling(Array);
        Print_Array(Array, sorted);
        Insercion(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        Continue();

        ISBN::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "Insercion" << white << std::setw(10) << ISBN::Cont_.getMin() << std::setw(9) << ISBN::Cont_.getMedia() << std::setw(9) << ISBN::Cont_.getMax() << "\n";

        Continue();

        ISBN::Cont_.start();

        sorted = false;
        Filling(Array);             // Lleno el array de ISBN aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Burbuja(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        Continue();

        ISBN::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "Burbuja" << white << std::setw(10) << ISBN::Cont_.getMin() << std::setw(9) << ISBN::Cont_.getMedia() << std::setw(9) << ISBN::Cont_.getMax() << "\n";

        Continue();

        ISBN::Cont_.start();

        sorted = false;
        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Quick(Array, 0, Array.size() - 1);
        sorted = true;
        Print_Array(Array, sorted);

        Continue();

        ISBN::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "QuickSort" << white << std::setw(10) << ISBN::Cont_.getMin() << std::setw(9) << ISBN::Cont_.getMedia() << std::setw(9) << ISBN::Cont_.getMax() << "\n";

        Continue();

        ISBN::Cont_.start();
        sorted = false;
        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Heap(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        Continue();

        ISBN::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "HeapSort" << white << std::setw(10) << ISBN::Cont_.getMin() << std::setw(9) << ISBN::Cont_.getMedia() << std::setw(9) << ISBN::Cont_.getMax() << "\n";

        Continue();

        ISBN::Cont_.start();
        sorted = false;
        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Shell(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        Continue();
        int g = getchar();

        ISBN::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "ShellSort" << white << std::setw(10) << ISBN::Cont_.getMin() << std::setw(9) << ISBN::Cont_.getMedia() << std::setw(9) << ISBN::Cont_.getMax() << "\n";
    }
}

void Continue()
{
    std::cout << "\n\nPresione enter para continuar...";
    int c = getchar();
}

void Print_Array(vector<ISBN> &V, bool sorted)
{

    if (sorted)
        std::cout << yellow << "Sorted: ";
    else
        std::cout << yellow << "Unsorted: ";

    for (int i = 0; i < V.size(); i++)
    {
        if (sorted)
            std::cout << red << V[i] << " ";
        else
            std::cout << green << V[i] << " ";
    }
    std::cout << endl
              << endl;
}

void Filling(vector<ISBN> &V)
{
    srand(time(NULL));
    for (int i = 0; i < V.size(); i++)
    {
        ISBN Num;
        V[i] = Num;
    }
}