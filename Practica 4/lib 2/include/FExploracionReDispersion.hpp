#pragma once
#include"FExploracionBase.hpp"

template<class Clave>
class FExploracionReDispersion : public
FExploracionBase<Clave>
{

public:
    FExploracionReDispersion(const int nceldas);
    ~FExploracionReDispersion();
    int operator()(const Clave &x, int i);
};

template<class Clave>
FExploracionReDispersion<Clave>::FExploracionReDispersion(int nceldas) {
    FExploracionBase<Clave>::T_ = nceldas;
}   
template<class Clave>
int FExploracionReDispersion<Clave>::operator()(const Clave &x, int i)
{
    srand(x);
    int resul = 0;
    if (i > 0)
    {
        for (int j = 1; j <= i; j++)
        {
            resul = rand() % FExploracionBase<Clave>::T_;
        }
    }
    return resul;
}