#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

template <class Clave>
void Insercion(std::vector<Clave> &V, int sz)
{

    int j;
    Clave x;
    for (int i = 1; i < sz; i++)
    {
        j = i - 1;
        x = V[i];

        while ((x < V[j]) && (j >= 0))
        {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = x;
    }
}
