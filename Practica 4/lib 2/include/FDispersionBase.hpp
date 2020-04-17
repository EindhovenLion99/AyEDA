#pragma once
#include <iostream>
#include <stdlib.h>

template<class Clave>
class FDispersionBase {

protected:

    int T_; //Tamaño de la tabla
public:
    FDispersionBase();
    virtual int operator()(const Clave &x) = 0;
};

template<class Clave>
FDispersionBase<Clave>::FDispersionBase()
{

}