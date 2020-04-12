#pragma once
#include <iostream>
#include <vector>

template <class Clave>
class Tabla;

template <class Clave>
class Celda
{
private:
    vector<Clave>;

public:
    Celda();
    ~Celda();
    bool Buscar(Clave X);
    bool Insertar(Clave X);
    bool estaLleno();
};