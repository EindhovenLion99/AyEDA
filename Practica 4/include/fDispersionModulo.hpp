#pragma once
#include <iostream>
#include "fDispersionBase.hpp"

template <class Clave>
class fDispersionModulo : public fDispersionBase<Clave>
{

    fDispersionModulo(int nCeldas) { ... }

    int operator()(const Clave &) { ... }
};