#pragma once
#include"FExploracionBase.hpp"

template<class Clave>
class FExploracionCuadratica : public
FExploracionBase<Clave>
{

public:
    FExploracionCuadratica(const int nceldas);
    ~FExploracionCuadratica();
    int operator()(const Clave &x, int i);
};

template<class Clave>
FExploracionCuadratica<Clave>::FExploracionCuadratica(const int nceldas) {
    
    FExploracionCuadratica<Clave>::T_= nceldas;
}

template<class Clave>
int FExploracionCuadratica<Clave>::operator()(const Clave &x, int i)
{
    return x*x;
}