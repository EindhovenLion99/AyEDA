#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

template <class Clave>
void Baja(std::vector<Clave> &V, int sz, int pos)
{
    int reg = pos;
    int h;
    int h1;
    int h2;
    while (2 * pos <= sz)
    {
        h1 = 2 * pos;
        h2 = h1 + 1;
        if (h1 == sz)
            h = h1;
        else if (V[h1] > V[h2])
        {
            h = h1;
        }
        else
            h = h2;

        if (V[h] <= V[pos])
            break;
        else
        {
            Clave aux = V[pos];
            V[pos] = V[h];
            V[h] = aux;
            pos = h;
        }
    }
    for (int j = 0; j < V.size(); j++)
    {
        if (j == sz || j == reg)
        {
            std::cout << "\33[1;31m"; // Aplicamos colores
        }
        else if ((j > reg && j < sz))
        {
            std::cout << "\33[1;36m"; // Aplicamos colores
        }
        if (j == h)
        {
            std::cout << "\33[1;32m"; // Aplicamos colores
        }
        std::cout << "| [" << j << "]" << V[j];
        std::cout << "\033[1;0m";
    }
    std::cout << "|";

    std::cout << std::endl;
}

template <class Clave>
void Heap(std::vector<Clave> &V, int sz)
{
    std::cout << std::endl
              << "Inserciones" << std::endl;
    std::cout << std::endl;

    for (int i = sz / 2 - 1; i >= 0; i--)
        Baja(V, sz, i);

    std::cout << std::endl
              << "Extracciones" << std::endl;

    for (int i = sz - 1; i > 0; i--)
    {
        Clave aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        Baja(V, i - 1, 0);
    }

    std::cout << std::endl;
}
