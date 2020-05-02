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
            for (int z = 0; z < sz; z++)
            {
                if (V[j] < V[j - 1])
                {
                    if (V[z] == V[j])
                        cout << red << " [" << z << "]" << V[z];
                    else if (V[z] == V[j - 1])
                        cout << blue << " [" << z << "]" << V[z];
                    else
                        cout << yellow << " [" << z << "]" << V[z];
                }
                else
                    cout << yellow << " [" << z << "]" << V[z];
            }
            std::cout << white << "\tBurbuja:" << V[j] << std::endl;
            std::cout << std::endl;
            if (V[j] < V[j - 1])
                cout << "Intercambiando con: " << V[j - 1] << std::endl
                     << std::endl;

            if (V[j] < V[j - 1])
            {
                Clave aux = V[j];
                V[j] = V[j - 1];
                V[j - 1] = aux;
            }
        }
    }
}