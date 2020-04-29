#include <iostream>
#include "termcolor.hpp"

using namespace termcolor;

template <class Clave>
void Quick(vector<Clave> &V, int ini, int fin)
{
    int i = ini;
    int f = fin;
    int p = V[(i + f) / 2];
    int c;

    for (int j = 0; j < V.size(); j++)
    {

        if (V[j] == p)
            std::cout << yellow << " [" << j << "]" << V[j];

        else if (j <= fin && j >= i)
            std::cout << blue << " [" << j << "]" << V[j];

        else
            std::cout << " [" << j << "]" << V[j];
    }
    std::cout << "\tPivote: " << p << std::endl;

    //
    c = getchar();
    while (i <= f)
    {
        while (V[i] < p)
            i++;
        while (V[f] > p)
            f--;
        if (i <= f)
        {
            Swap_Q(V[i], V[f]);
            i++;
            f--;
        }
    }
    if (ini < f)
        Quick(V, ini, f);
    if (i < fin)
        Quick(V, i, fin);
};

template <class Clave>
void Swap_Q(Clave &P, Clave &N)
{
    Clave aux = P;
    P = N;
    N = aux;
};
