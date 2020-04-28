#pragma once
#include "vector_t.hpp"
#include "termcolor.hpp"

using namespace termcolor;
using namespace std;

template <class Clave>
void Shell(Vector_T<Clave> &V, int sz)
{
    int delta = sz;
    while (delta > V.start())
    {
        delta = delta / 2;
        deltasort(delta, V, sz);
    }
}

template <class Clave>
void deltasort(int delta, Vector_T<Clave> &V, int sz)
{
    cout << "δ: " << delta << endl;
    int j;
    Clave aux;
    for (int i = delta; i <= sz; i++)
    {
        aux = V[i];
        j = i;
        while ((j - V.start() >= delta) && (aux < V[j - delta]))
        {
            V[j] = V[j - delta];
            j = j - delta;
        }
        V[j] = aux;
        for (int k = V.start(); k <= V.end(); k++)
        {
            if (V[k] == V[i] || (V[k] == V[i - delta + V.start()]))
                cout << yellow << " | [" << k << "]" << V[k];
            else
                cout << blue << " | [" << k << "]" << V[k];
        }
        cout << endl
             << endl;
    }
}