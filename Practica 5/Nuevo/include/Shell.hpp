#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

template <class Clave>
void deltasort(std::vector<Clave> &V, int delta, int sz)
{
    std::cout << "δ: " << delta << std::endl
              << std::endl;
    Clave aux;
    for (int i = delta; i < V.size(); i++)
    {
        aux = V[i];
        int j = i;
        while ((j - 0 >= delta) && (aux < V[j - delta]))
        {
            V[j] = V[j - delta];
            j = j - delta;
        }
        V[j] = aux;
        for (int k = 0; k < V.size(); k++)
        {
            if (V[k] == V[i] || (V[k] == V[i - delta + 1]))
                std::cout << yellow << " | [" << k << "]" << V[k];
            else
                std::cout << blue << " | [" << k << "]" << V[k];
        }
        std::cout << std::endl
                  << std::endl;
    }
}

template <class Clave>
void Shell(std::vector<Clave> &V, int sz)
{
    int delta = sz;
    while (delta > 0)
    {
        delta = delta / 2;
        deltasort(V, delta, sz);
    }
}
