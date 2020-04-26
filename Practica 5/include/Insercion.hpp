#pragma once
#include <vector>
#include <iostream>

template <class Clave>
void Insercion(vector<Clave> &V, int sz)
{
    for (int i = V.begin(); i != V.end(); i++)
    {
        int pos = i;
        Clave j = V[i];
        while ((pos > V.begin()) && (j < V[pos - 1]))
        {
            V[pos] = V[pos - 1];
            pos--;
        }
        V[pos] = j;
    }
}