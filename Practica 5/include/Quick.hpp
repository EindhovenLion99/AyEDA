#include <iostream>
#include <vector>

template <class Clave>
void Quick(vector<Clave> &V, int ini, int fin)
{
    int i = ini;
    int f = fin;
    int p = V[(i + f) / 2];
    while (i <= f)
    {
        while (V[i] < p)
            i++;
        while (V[f] > p)
            f--;
        if (i <= f)
        {
            Swap(V[i], V[f]);
            i++;
            f--;
        }
    }
    if (ini < f)
        Quick(V, ini, f);
    if (i < fin)
        Quick(V, i, fin);
}
