#pragma once
#include <iostream>
#include "fDispersionBase.hpp"
#include "fExploracionBase.hpp"
#include "Celda.hpp"

template <class Clave>
class Tabla
{
private:
    Celda<Clave> *vCleda;
    fDispersionBase<Clave> *h;
    fExploracionBase<Clave> *g;

public:
    Tabla();
    ~Tabla();
    bool Buscar(Clave X);
    bool Insertar(Clave X);
    bool estaLleno();
};