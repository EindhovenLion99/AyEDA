#pragma once
#include <vector>
#include <iostream>

template <class Clave>
void Insercion(Vector_T<Clave> &V, int sz)
{
    for (int i = V.start(); i <= V.end(); i++)
    {
        int pos = i;
        Clave a = V[i];
        std::cout << " \n\n";
        while ((pos > V.start()) && (a < V[pos - 1]))
        {
            V[pos] = V[pos - 1];
            for (int j = V.start(); j <= V.end(); j++)
            {
                if (V[j] == V[pos])
                {
                    std::cout << "\033[1;31m";
                    std::cout << "<-[" << j << "] " << V[j];
                }
                else
                {
                    std::cout << "| [" << j << "] " << V[j];
                }
                std::cout << "\033[1;0m";
            }
            std::cout << " |\n";
            pos--;
        }
        std::cout << " \n\n";
        V[pos] = a;
        for (int k = V.start(); k <= V.end(); k++)
        {
            if (V[pos + 1] == V[k])
                std::cout << "\033[1;31m";
            if (pos >= k)
            {
                std::cout << "\033[1;0m";
                std::cout << "\033[1;32m";
            }
            std::cout << "| [" << k << "] " << V[k];
            std::cout << "\033[1;0m";
        }

        std::cout << " |\n";
        std::cout << "\n----------------Siguiente vuelta----------------\n";
        int c;
        c = getchar();
    }
}