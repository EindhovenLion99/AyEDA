#pragma once
#include <iostream>
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

template <class Clave>
class nodoB
{
public:
    // Atributos
    Clave Dato;
    nodoB<Clave> *Izq;
    nodoB<Clave> *Der;

public:
    // Cosntructor
    nodoB(Clave dato, nodoB *Iz = nullptr, nodoB *De = nullptr)
    {
        Dato = dato;
        Izq = Iz;
        Der = De;
    };
    // Destructor
    ~nodoB(){};

    virtual Clave Get_Dato() { return Dato; }
    virtual void Print_Dato() { Dato.Print(cout); }
    virtual void Set_Dato(Clave dato) { Dato = dato; }

    nodoB *Get_Izq() { return Izq; }
    nodoB *Get_Der() { return Der; }
};

template <class Clave>
class nodoBB : public nodoB<Clave>
{

public:
    // nodoBB(Clave dato) : Dato(dato) {}
    nodoBB(Clave dato) : nodoB<Clave>(dato)
    {
    }
};