#pragma once
#include <iostream>
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

template <class Clave>
class nodoBB
{
private:
    // Atributos
    Clave Dato;
    nodoBB *Izq;
    nodoBB *Der;

public:
    // Cosntructor
    nodoBB(){};
    nodoBB(Clave dato)
    {
        Dato = dato;
        Izq = NULL;
        Der = NULL;
    }
    // Destructor
    ~nodoBB(){};

    Clave Get_Dato() { return Dato; }
    void Print_Dato() { Dato.Print(cout); }

    nodoBB *Get_Izq() { return Izq; }
    nodoBB *Get_Der() { return Der; }
};