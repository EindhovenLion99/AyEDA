#include <iostream>
#include "vector_t.hpp"
#include "termcolor.hpp"

using namespace termcolor;

template <class Clave>
void Quick(Vector_T<Clave> &V, int ini, int fin)
{
    int i = ini;
    int f = fin;
    int p = V[(i + f) / 2];

    for (int j = V.start(); j <= V.end(); j++)
    {

        if (V[j] == p)
            std::cout << yellow << " [" << j << "]" << V[j];

        else if (j <= fin && j >= i)
            std::cout << blue << " [" << j << "]" << V[j];

        else
            std::cout << " [" << j << "]" << V[j];
    }
    std::cout << "\tPivote: " << p << std::endl;
    int c;
    c = getchar();

    while (i <= f)
    {
        while (V[i] < p)
            i++;
        while (V[f] > p)
            f--;
        if (i <= f)
        {
            Swap(V[i], V[f]);
            i++;
            f--;
        }
    }
    if (ini < f)
        Quick(V, ini, f);
    if (i < fin)
        Quick(V, i, fin);
}
