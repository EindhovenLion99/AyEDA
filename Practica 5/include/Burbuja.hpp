#pragma once
#include <iostream>
#include <vector>

template <class Clave>
void Burbuja(vector<Clave> &V, int sz)
{
    for (int i = 1; i < sz; i++)
    {
        for (int j = 1; j < sz - i; j++)
        {
            if (V[j] > V[j + 1])
            {
                V[j].swap(V[j + 1]);
            }
        }
    }
}