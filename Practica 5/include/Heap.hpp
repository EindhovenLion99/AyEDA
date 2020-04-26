#pragma once
#include <iostream>
#include <vector>

template <class Clave>
void Baja(vector<Clave> &V, int sz, int pos)
{
    while (2 * pos <= sz)
    {
        int h;
        int h1 = 2 * pos;
        int h2 = h1 + 1;
        if (h1 == sz)
            h = h1;
        else if (V[h1] > V[h2])
            h = h1;
        else
            h = h2;

        if (V[h] <= V[pos])
            break;
        else
        {
            Swap(V[pos], V[h]);
            pos = h;
        }
    }
}

template <class Clave>
void Heap_Sort(vector<Clave> &V, int sz)
{
    for (int i = sz / 2; i > 0; i--)
        Baja(V, sz, i);

    for (int i = sz; i > 1; i--)
    {
        Swap(V[1], V[i]);
        Baja(V, i - 1, 1);
    }
}

template <class Clave>
void Swap(Clave &P, Clave &N)
{
    Clave aux = P;
    P = N;
    N = aux;
}