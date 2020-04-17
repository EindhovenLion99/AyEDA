#pragma once
#include "FExploracionBase.hpp"


template<class Clave>
class FExploracionDoble : public
FExploracionBase<Clave>
{
private:

    FDispersionSuma<Clave> *fDispS;
public:
    FExploracionDoble(const int nceldas);
    ~FExploracionDoble();
    int operator()(const Clave &x, int i);

};

template<class Clave>
FExploracionDoble<Clave>::FExploracionDoble(int nCeldas)
{
    FExploracionBase<Clave>::T_ = nCeldas;
    fDispS = new FDispersionSuma<Clave>(FExploracionBase<Clave>::T_);
}

template<class Clave>
int FExploracionDoble<Clave>::operator()(const Clave &x, int i)
{
    return ((*fDispS)(x)*i) % FExploracionBase<Clave>::T_;
}