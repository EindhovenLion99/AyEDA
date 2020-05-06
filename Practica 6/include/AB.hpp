#pragma once
#include <iostream>
#include "nodoBB.hpp"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

template <class Clave>
class AB
{
private:
    nodoBB<Clave> *Raiz = NULL;

public:
    AB() {}
    ~AB(){};

    virtual bool Buscar(Clave Valor) = 0;
    virtual void Insertar(Clave Valor) = 0;
    virtual void Eliminar(Clave Valor) = 0;
};

template <class Clave>
class ABB : public AB<Clave>
{
private:
    nodoBB<Clave> *Raiz;

public:
    ABB() { Raiz = NULL; };
    ~ABB(){};

    virtual bool Buscar(Clave Valor) { return BuscarRama(Raiz, Valor); }
    virtual void Insertar(Clave Valor) { InsertarRama(Raiz, Valor); }
    virtual void Eliminar(Clave Valor) { EliminarRama(Raiz, Valor); }

    void Write(ostream &os)
    {
        if (Raiz == NULL)
        {
            os << "Arbol vacio:\n [.] \n";
        }
        else
        {
            nodoBB<Clave> *Nodo = Raiz;
            int i = 0;
            Recorrer(os, Nodo, i);
        }
    }

private:
    bool BuscarRama(nodoBB<Clave> *Nodo, Clave Valor)
    {
        if (Nodo == NULL)
            return false;
        if (Nodo->Get_Dato() == Valor)
            return true;
        if (Nodo->Get_Dato() < Valor)
            BuscarRama(Nodo->Get_Izq(), Valor);
        BuscarRama(Nodo->Get_Der(), Valor);
    }

    void InsertarRama(nodoBB<Clave> *Nodo, Clave Valor)
    {
        if (Nodo == NULL)
        {
            Nodo = new nodoBB(Valor);
        }
        else if (Valor < Nodo->Get_Dato())
            InsertarRama(Nodo->Get_Izq(), Valor);
        else
            InsertarRama(Nodo->Get_Der(), Valor);
    }

    void EliminarRama(nodoBB<Clave> *Nodo, Clave Valor)
    {
        if (Nodo == NULL)
            return;
        if (Valor < Nodo->Get_Dato())
            EliminarRama(Nodo->Get_Izq(), Valor);
        else if (Valor > Nodo->Get_Dato())
            EliminarRama(Nodo->Get_Der(), Valor);
        else
        {
            nodoBB<Clave> *Eliminado = Nodo;
            if (Nodo->Get_Der() == NULL)
                Nodo = Nodo->Get_Izq();
            else if (Nodo->Get_Izq() == NULL)
                Nodo = Nodo->Get_Der();
            else
                Sustituye(Eliminado, Nodo->Get_Izq());
            delete (Eliminado);
        }
    }

    void Sustituye(nodoBB<Clave> *Eliminado, nodoBB<Clave> *Sustituto)
    {
        if (Sustituto->Get_Der() != NULL)
            Sustituye(Eliminado, Sustituto->Get_Der());
        else
        {
            // Eliminado->Get_Dato() = Sustituto->Get_Dato();
            Eliminado = Sustituto;
            Sustituto = Sustituto->Get_Izq();
        }
    }

    void Recorrer(std::ostream &os, nodoBB<Clave> *Nodo, int i)
    {
        os << "Nivel " << i << ": [" << Nodo->Get_Dato() << "] ";

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