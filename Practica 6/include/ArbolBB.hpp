#pragma once
#include <iostream>
#include "nodoBB.hpp"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

template <class Clave>
class ArbolBB
{
private:
    nodoBB<Clave> *Raiz;

public:
    ArbolBB() { Raiz = NULL; }
    ~ArbolBB(){};

    nodoBB *Buscar(int Valor) { return BuscarRama(Raiz, Valor); }
    void Insertar(int Valor) { InsertarRama(Raiz, Valor); }
    void Eliminar(int Valor) { EliminarRama(Raiz, Valor); }

    void Write(ostream &os)
    {
        if (Raiz == NULL)
        {
            os << "Arbol vacio:\n [.] \n"
        }
        else
        {
            nodoBB<Clave> *Nodo = Raiz;
            int i = 0;
            Recorrer(os, Nodo, i);
        }
    }

    void Recorrer(std::ostream &os, nodoBB<Clave> *Nodo, int i)
    {
        os << "Nivel " << i << ": [" Nodo->Print_Dato() << "] ";

        if (Nodo->Get_Izq() != NULL)
        {
            Recorrer(os, Nodo->Get_Izq(), i++);
        }

        if (Nodo->Get_Der() != NULL)
        {
            Recorrer(os, Nodo->Get_Der(), i++);
        }
    }
};