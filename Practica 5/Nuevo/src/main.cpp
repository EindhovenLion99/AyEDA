#include <iostream>
#include <vector>
#include "DNI.hpp"
#include "Insercion.hpp"
#include "Burbuja.hpp"
#include "Heap.hpp"
#include "Quick.hpp"
#include "Shell.hpp"
#include "termcolor.hpp"

using namespace termcolor;

void Print_Array(vector<DNI> &V, bool sorted);
void Print_Ar(vector<int> &V, bool sorted);
void Filling(vector<DNI> &V);

int main()
{
    bool sorted = false;
    int opc;

    std::cout << white << "Elige el metodo de ordenacion (1...5): ";
    std::cin >> opc;

    std::cout << endl;

    std::vector<DNI> Array(10);
    Filling(Array);             // Lleno el array de DNI aleatorios
    Print_Array(Array, sorted); // Imprimo el array

    switch (opc)
    {

    case 1:
        Insercion(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        break;
    case 2:
        Burbuja(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        break;
    case 3:
        Quick(Array, 0, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        break;
    case 4:
        Heap(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        break;
    case 5:
        Shell(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        break;

    default:
        break;
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