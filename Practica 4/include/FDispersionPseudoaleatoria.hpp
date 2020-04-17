#pragma once
#include "FDispersionBase.hpp"

template <class Clave>
class FDispersionPseudoaleatoria : public
FDispersionBase<Clave>
{

public:
    FDispersionPseudoaleatoria(const int nceldas);
    ~FDispersionPseudoaleatoria();
    int operator()(const Clave &x);

};
template<class Clave>
FDispersionPseudoaleatoria<Clave>::FDispersionPseudoaleatoria(const int nceldas) {
    
    FDispersionBase<Clave>::T_ = nceldas; 
}

template<class Clave>
FDispersionPseudoaleatoria<Clave>::~FDispersionPseudoaleatoria() {

}

template<class Clave>
int FDispersionPseudoaleatoria<Clave>::operator()(const Clave &x)
{
    srand(x);
        return rand() % FDispersionBase<Clave>::T_;
}