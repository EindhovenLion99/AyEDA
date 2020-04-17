#pragma once
#include <iostream>
#include <cstdlib>

template<class Clave>
class FExploracionBase {
protected:
    int T_;
public:
    FExploracionBase();
    virtual int operator()(const Clave &x, int i) = 0;
};

template<class Clave>
FExploracionBase<Clave>::FExploracionBase()
{

}