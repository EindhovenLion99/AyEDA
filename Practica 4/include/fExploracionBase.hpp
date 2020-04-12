#pragma once

template <class Clave>
class fExploracionBase
{
public:
    virtual int fExploracionBase<Clave>::operator()(const Clave &, int i) = 0;
};