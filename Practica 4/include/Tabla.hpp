#pragma once
#include <iostream>

template <class Clave>
class Tabla
{
private:
    Clave **vCelda;

public:
    Tabla();
    ~Tabla();
    bool Buscar(Clave X);
    bool Insertar(Clave X);
};