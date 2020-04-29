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
        for (int z = 0; z < V.size(); z++)
        {
            if (V[z] == x)
            {
                std::cout << yellow << " [" << z << "]" << V[z];
            }
            else
            {
                std::cout << blue << " [" << z << "]" << V[z];
            }
        }
        std::cout << blue << " \tPivote: " << x << std::endl
                  << endl;
    }
}
