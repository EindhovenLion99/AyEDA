#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

template <class Clave>
void Burbuja(std::vector<Clave> &V, int sz)
{
    for (int i = 1; i < sz; i++)
    {
        for (int j = sz - 1; j >= i; j--)
        {
            if (V[j] < V[j - 1])
            {
                DNI aux = V[j];
                V[j] = V[j - 1];
                V[j - 1] = aux;
            }
        }
    }
}