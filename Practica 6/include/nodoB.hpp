#pragma once
#include <iostream>
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

template <class Clave>
class nodoB
{
public:
    Clave Dato;
    nodoB<Clave> *Izq;
    nodoB<Clave> *Der;

public:
    nodoB(Clave dato)
    {
        Dato = dato;
        Izq = nullptr;
        Der = nullptr;
    };
    ~nodoB(){};
};

template <class Clave>
class nodoBB : public nodoB<Clave>
{
public:
    nodoBB<Clave> *Izq;
    nodoBB<Clave> *Der;

public:
    nodoBB(Clave dato) : nodoB<Clave>(dato)
    {
        Izq = NULL;
        Der = NULL;
    }
    ~nodoBB(){};
};