#pragma once
#include"FExploracionBase.hpp"

template<class Clave>
class FExploracionLineal : public
FExploracionBase<Clave>
{

public:
    FExploracionLineal(const int nceldas);
    ~FExploracionLineal();
    int operator()(const Clave &x, int i);
};

template<class Clave>
FExploracionLineal<Clave>::FExploracionLineal(const int nceldas) {
    FExploracionBase<Clave>::T_ = nceldas; 
}

template<class Clave>
int FExploracionLineal<Clave>::operator()(const Clave &x, int i)
{
    return x;
}