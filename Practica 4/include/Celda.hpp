#pragma once
#include <iostream>
#include "DNI.hpp"
#include <vector>

using namespace std;

template <class Clave>
class Celda
{
private:
    vector<Clave> vCeldas;
    int NumClaves;

public:
    Celda();
    Celda(int nClaves);
    ~Celda();
    int inline isfull(void) { return numElem() == vCeldas.size(); }

    bool Buscar(Clave X);
    bool Insertar(Clave &X);
    int numElem();
};