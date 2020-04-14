#include "Tabla.hpp"

template <class Clave>
Tabla<Clave>::Tabla(int nCeldas, int nClaves, int fDisp, int fExp)
{
    v = new Celda<Clave>[nCeldas];
    NumCeldas = nCeldas;
    for (int i = 0; i < nCeldas; i++)
    {
        v[i] = Celda<Clave>(nClaves);
    }

    switch (fDisp)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
    switch (fExp)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}

template <class Clave>
Tabla<Clave>::~Tabla()
{
}

template <class Clave>
bool Tabla<Clave>::Buscar(Clave X)
{
    for (int i = 0; i < NumCeldas; i++)
    {
        if (v[i].Buscar(X))
        {
            return true;
        }
    }
    return false;
}

template <class Clave>
bool Tabla<Clave>::Insertar(Clave X)
{
    for (int i = 0; i < NumCeldas; i++)
    {
        if (v[i].Insertar(X))
        {
            return true;
        }
    }
    return false;
}
