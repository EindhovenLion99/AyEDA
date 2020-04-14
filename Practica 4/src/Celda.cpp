#include "Celda.hpp"

template <class Clave>
Celda<Clave>::Celda()
{
}

template <class Clave>
Celda<Clave>::Celda(int nClaves)
{
    vCeldas.resize(nClaves);
    for (int i = 0; i < vCeldas.size(); i++)
    {
        vCeldas[i].set_none();
    }
}

template <class Clave>
Celda<Clave>::~Celda()
{
}

template <class Clave>
bool Celda<Clave>::Buscar(Clave X)
{
    {
        sort(vCeldas.begin(), vCeldas.end());

        int start = 0;
        int end = vCeldas.size();
        int position = start;

        while (start < end)
        {
            position = (start + end) / 2;
            if (vCeldas[position] == X)
            {
                return true;
            }
            else
            {
                if (vCeldas[position] < X)
                    start = position + 1;
                else
                    end = position - 1;
            }
        }
        if (vCeldas[start] == X)
            return true;
        return false;
    }
}

template <class Clave>
bool Celda<Clave>::Insertar(Clave &X)
{
    for (int i = 0; i < vCeldas.size(); i++)
    {
        if (vCeldas[i].value() == -1)
        {
            vCeldas[i] = X;
            return true;
        }
    }
    return false;
}

template <class Clave>
int Celda<Clave>::numElem()
{
    int elem = 0;
    for (int i = 0; i < vCeldas.size(); i++)
    {
        if (vCeldas[i].value() != -1)
            elem++;
    }

    return elem;
}
