#pragma once

template <class Clave>
class fDispersionBase
{
public:
    virtual int operator()(const Clave &) = 0;
};