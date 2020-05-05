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

    void Set_Izq(nodoBB *N) { Izq = N; }
    void Set_Der(nodoBB *N) { Der = N; }

    nodoBB Get_Izq(nodoBB *N) { return Izq; }
    nodoBB Get_Der(nodoBB *N) { return Der; }
};