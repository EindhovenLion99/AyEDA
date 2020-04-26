#pragma once
#include <vector>
#include <iostream>

template <class Clave>
void Insercion(vector<Clave> &V, int sz)
{
    for (int i = 0; i <= sz; i++)
    {
        int pos = i;
        Clave j = V[i];
        int start = V[0];
        while ((pos > start) && (j < V[pos - 1]))
        {
            V[pos] = V[pos - 1];
            pos--;
        }
        V[pos] = j;
    }
}