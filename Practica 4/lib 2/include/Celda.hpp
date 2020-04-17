#pragma once
#include <iostream>
#include "DNI.hpp"
#include "FDispersionBase.hpp"
#include "FExploracionBase.hpp"

using namespace std;
template<class Clave>
class Celda {

private:

    int nClave_;
    Clave *vClave_;


public:
    Celda(int nClave);
    ~Celda();

    bool Search(Clave x);
    bool Insert(Clave x);
    bool Full();
};

template<class Clave>
Celda<Clave>::Celda(int nClave) {
    nClave_ = nClave;
    vClave_ = new Clave(nClave_);
    for(int i = 0; i < nClave_; i++)
        vClave_[i] = -1;
}

template<class Clave>
bool Celda<Clave>::Search(Clave x)
{
    int pos = 0;
    int ini = 0;
    int fin = nClave_;
        while(ini < fin)
        {
            pos = (ini + fin) / 2;
            if(vClave_[pos] == x)
                return pos;
            else
                if(vClave_[pos] < x)
                    ini = pos + 1;
                else
                    fin = pos - 1;
        }
        if( vClave_[ini] == x)
            return ini;
    return -1;
}

template<class Clave>
bool Celda<Clave>::Insert(Clave x)
{
    for(int i = 0; i < nClave_; i++)
        if(!Full())
            return false;
        else
        {
            vClave_[i] = x;
            return true;
        }
}

template<class Clave>
bool Celda<Clave>::Full(void)
{
    if( vClave_[nClave_].value() == -1)
        return false;
    else    
        return true;
}

template<class Clave>
Celda<Clave>::~Celda()
{
    delete[] vClave_;
}