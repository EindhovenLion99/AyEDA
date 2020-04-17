#pragma once
#include"FDispersionBase.hpp"

template <class Clave>
class FDispersionModulo : public
FDispersionBase<Clave>
{
private:
    int T_;
public:
    FDispersionModulo(const int nceldas);
    int operator()(const Clave &x);
};



template <class Clave>
FDispersionModulo<Clave>::FDispersionModulo(const int nceldas) {
   T_ = nceldas; 
}

template <class Clave>
int FDispersionModulo<Clave>::operator()(const Clave &x)
{
    return(x % T_);
}