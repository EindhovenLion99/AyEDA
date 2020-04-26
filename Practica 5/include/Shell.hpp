#pragma once
#include <iostream>
#include <vector>

template <class Clave>
void Shell(vector<Clave> &V, int sz)
{
    int delta = sz;
    while (delta > 1)
    {
        delta = delta / 2;
        deltasort(delta, V, sz);
    }
}

template <class Clave>
void deltasort(int delta, vector<Clave> &V, int sz)
{
    for (int i = delta; i <= sz; i++)
    {
        Clave aux = V[i];
        int j = i;
        while (((j - V.begin()) >= delta) && (aux < V[j - delta]))
        {
            V[j] = V[j - delta];
            j = j - delta;
        }
        V[j] = aux;
    }
}