#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class Clave>
class Celda
{

    int indice;
    vector<Clave> Bloque_;

  public:

    Celda(int nBloques = 0)
    {
        resize(nBloques);
        indice = 0;
    }

    void resize(int nBloques = 0)
    {
        Bloque_.resize(nBloques);
        if (indice > nBloques)
            indice = nBloques;
    }

    bool buscar(const Clave x)
    {
        for (int i = 0; i < Bloque_.size(); i++)
        {
            if (Bloque_[i] == x)
                return true;
        }
        return false;
    }

    bool buscar( Clave x, int &cont)
    {
        for (int i = 0; i < Bloque_.size(); i++)
        {
            cont++;
            if (Bloque_[i] == x)
                return true;
        }
        return false;
    }

    bool insertar(Clave x)
    {
        if (!esta_llena())
        {
            Bloque_[indice] = x;
            indice++;
            return true;
        }
        return false;
    }
    bool esta_llena()
    {
        if (indice >= Bloque_.size())
            return true;
        return false;
    }

    void Print() const
    {
        for (int i = 0; i < Bloque_.size(); i++)
        {
            cout << setw(10);
            Bloque_[i].Print(cout);
        }
    }
};
