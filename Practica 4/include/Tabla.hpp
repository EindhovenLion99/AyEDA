#pragma once
#include <iostream>
#include "fDispersionBase.hpp"
#include "fExploracionBase.hpp"
#include "Celda.hpp"

template <class Clave>
class Tabla
{
private:
    Celda<Clave> **v;
    fDispersionBase<Clave> *h;
    fExploracionBase<Clave> *g;
    int NumCeldas;

public:
    Tabla(int nCeldas, int nClaves, int fDisp, int fExp);
    ~Tabla();
    bool Buscar(Clave X);
    bool Insertar(Clave X);
};