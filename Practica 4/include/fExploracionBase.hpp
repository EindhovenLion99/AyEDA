#pragma once

template <class Clave>
class fExploracionBase
{
public:
    virtual int operator()(const Clave &, int i) = 0;
};