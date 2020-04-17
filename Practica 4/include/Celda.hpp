#pragma once
#include <iostream>
#include "DNI.hpp"
#include "FDispersionBase.hpp"
#include "FExploracionBase.hpp"
#include <vector>

using namespace std;
template <class Clave>
class Celda
{

private:
    int nClave_;
    vector<Clave> vClave_;
    FDispersionBase<Clave> *h_;
    FExploracionBase<Clave> *g_;

public:
    Celda(int nClave);
    ~Celda();

    bool Search(Clave x);
    bool Insert(Clave x);
    bool Full();

    Clave &operator[](int pos) { return vClave_[pos]; }
};

template <class Clave>
Celda<Clave>::Celda(int nClave)
{
    vClave_.resize(nClave);
    for (int i = 0; i < vClave_.size(); i++)
        vClave_[i].value(-1);
}

template <class Clave>
bool Celda<Clave>::Search(Clave x)
{
    int pos = 0;
    int ini = 0;
    int fin = nClave_;
    while (ini < fin)
    {
        pos = (ini + fin) / 2;
        if (vClave_[pos] == x)
            return pos;
        else if (vClave_[pos] < x)
            ini = pos + 1;
        else
            fin = pos - 1;
    }
    if (vClave_[ini] == x)
        return ini;
    return -1;
}

template <class Clave>
bool Celda<Clave>::Insert(Clave x)
{
    if (Search(x))
        return false;

    for (int i = 0; i < vClave_.size(); i++)
    {
        if ((vClave_[i].value() == -1)) // .matr() modif
        {
            vClave_[i] = x;
            return true;
        }
    }
    return false;
}

template <class Clave>
bool Celda<Clave>::Full(void)
{
    if (vClave_[nClave_].value() == -1) // .matr() modif
        return false;
    else
        return true;
}

template <class Clave>
Celda<Clave>::~Celda()
{
    delete[] vClave_;
}