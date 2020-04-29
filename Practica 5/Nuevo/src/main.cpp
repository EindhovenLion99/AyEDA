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

Contador DNI::Cont_;

using namespace termcolor;

void Print_Array(vector<DNI> &V, bool sorted);
void Print_Ar(vector<int> &V, bool sorted);
void Filling(vector<DNI> &V);

int main()
{
    bool sorted = false;
    int opc, pruebas, N, c;

    std::cout << yellow << "Introduce tamaño del vector: " << white;
    std::cin >> N;
    std::cout << yellow << "Introduce número de pruebas: " << white;
    std::cin >> pruebas;

    std::cout << endl;

    std::vector<DNI> Array;
    Array.resize(N);

    std::cout << std::endl;

    for (int i = 0; i < pruebas; i++)
    {
        DNI::Cont_.start();

        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Insercion(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        c = getchar();

        DNI::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "Insercion" << white << std::setw(10) << DNI::Cont_.getMin() << std::setw(9) << DNI::Cont_.getMedia() << std::setw(9) << DNI::Cont_.getMax() << "\n";

        c = getchar();

        DNI::Cont_.start();

        sorted = false;
        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Burbuja(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        c = getchar();

        DNI::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "Insercion" << white << std::setw(10) << DNI::Cont_.getMin() << std::setw(9) << DNI::Cont_.getMedia() << std::setw(9) << DNI::Cont_.getMax() << "\n";

        c = getchar();
        DNI::Cont_.start();

        sorted = false;
        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Quick(Array, 0, Array.size() - 1);
        sorted = true;
        Print_Array(Array, sorted);

        c = getchar();

        DNI::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "Insercion" << white << std::setw(10) << DNI::Cont_.getMin() << std::setw(9) << DNI::Cont_.getMedia() << std::setw(9) << DNI::Cont_.getMax() << "\n";

        c = getchar();

        DNI::Cont_.start();
        sorted = false;
        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Heap(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        c = getchar();

        DNI::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "Insercion" << white << std::setw(10) << DNI::Cont_.getMin() << std::setw(9) << DNI::Cont_.getMedia() << std::setw(9) << DNI::Cont_.getMax() << "\n";

        c = getchar();

        DNI::Cont_.start();
        sorted = false;
        Filling(Array);             // Lleno el array de DNI aleatorios
        Print_Array(Array, sorted); // Imprimo el array
        Shell(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);

        c = getchar();

        DNI::Cont_.stop();
        std::cout << red << "Número de comparaciones:\n\n";
        std::cout << yellow << std::setw(20) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo\n";
        std::cout << "Insercion" << white << std::setw(10) << DNI::Cont_.getMin() << std::setw(9) << DNI::Cont_.getMedia() << std::setw(9) << DNI::Cont_.getMax() << "\n";
    }
}

void Print_Array(vector<DNI> &V, bool sorted)
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

void Filling(vector<DNI> &V)
{
    srand(time(NULL));
    for (int i = 0; i < V.size(); i++)
    {
        DNI Num;
        V[i] = Num;
    }
}