#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "nodoB.hpp"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

template <class Clave>
class AB
{
private:
    nodoB<Clave> *Raiz;

public:
    AB()
    {
        Raiz = nullptr;
    }
    ~AB(){};

    bool isNull()
    {
        if (Raiz == nullptr)
            return true;
        return false;
    }

    bool Buscar(Clave Valor) { return BuscarRama(Valor, Raiz); }
    void Insertar(Clave Valor) { InsertarRama(Valor, Raiz); }
    void Eliminar(Clave Valor) { EliminarRama(Valor, Raiz); }

    bool BuscarRama(Clave Valor, nodoB<Clave> *&Nodo)
    {
        if (Nodo == NULL)
            return false;
        if (Nodo->Dato == Valor)
            return true;
        if (Nodo->Dato < Valor)
        {
            BuscarRama(Valor, Nodo->Izq);
        }
        BuscarRama(Valor, Nodo->Der);
    }

    void InsertarRama(Clave Valor, nodoB<Clave> *&Nodo)
    {
        if (Nodo == nullptr)
        {
            Nodo = new nodoB<Clave>(Valor);
        }
        else if (Valor < Nodo->Get_Dato())
        {
            InsertarRama(Valor, Nodo->Izq);
        }
        else
        {
            InsertarRama(Valor, Nodo->Der);
        }
        //cout << "Valor: " << Valor.get_DNI() << endl;
    }
    void EliminarRama(Clave Valor, nodoB<Clave> *&Nodo)
    {
        if (Nodo == NULL)
            return;
        if (Valor < Nodo->Get_Dato())
        {
            //nodoBB<Clave> *Izq_;
            //Izq_ = new nodoBB<Clave>(Nodo->Izq->Dato);
            EliminarRama(Valor, Nodo->Get_Izq());
        }
        else if (Valor > Nodo->Dato)
        {
            //nodoBB<Clave> *Der_;
            //Der_ = new nodoBB<Clave>(Nodo->Der->Dato);
            EliminarRama(Valor, Nodo->Get_Der());
        }
        else
        {
            nodoBB<Clave> *Eliminado = Nodo;
            //nodoBB<Clave> *Der_, *Izq_;
            //Der_ = new nodoBB<Clave>(Nodo->Der->Dato);
            //Izq_ = new nodoBB<Clave>(Nodo->Izq->Dato);
            if (Nodo->Get_Der() == NULL)
                Nodo = Nodo->Get_Izq();
            else if (Nodo->Get_Izq() == NULL)
                Nodo = Nodo->Get_Der();
            else
                Sustituye(Eliminado, Nodo->Get_Izq());
            delete (Eliminado);
        }
    }

    void Sustituye(nodoB<Clave> *&Eliminado, nodoB<Clave> *&Sustituto)
    {
        //nodoBB<Clave> *Der_, *Izq_;
        //Der_ = new nodoBB<Clave>(Sustituto->Der->Dato);
        //Izq_ = new nodoBB<Clave>(Sustituto->Izq->Dato);
        if (Sustituto->Get_Der() != NULL)
            Sustituye(Eliminado, Sustituto->Get_Der());
        else
        {
            // Eliminado->Get_Dato() = Sustituto->Get_Dato();
            Eliminado = Sustituto;
            Sustituto = Sustituto->Get_Izq();
        }
    }

    void Write(ostream &os)
    {
        if (Raiz == NULL)
        {
            os << red << "Arbol vacio:\nNivel 0: [.]" << white << endl;
        }
        else
        {
            nodoB<Clave> *Nodo = Raiz;
            int i = 0;
            Recorrer(os, Nodo, i++);
        }
    }

    void Recorrer(std::ostream &os, nodoB<Clave> *Nodo, int i)
    {

        os << "Nivel " << i << ": [" << Nodo->Get_Dato() << "] " << endl;
        if (i == 0)
        {
            os << "Nivel " << ++i << ": [.] [.] " << endl;
        }

        if (Nodo->Get_Izq() != NULL)
        {
            Recorrer(os, Nodo->Get_Izq(), ++i);
        }

        if (Nodo->Get_Der() != NULL)
        {
            Recorrer(os, Nodo->Get_Der(), ++i);
        }
    }
};

template <class Clave>
class ABB : public AB<Clave>
{
public:
    ABB() : AB<Clave>()
    {
    }
    ~ABB(){};

    //bool Buscar(Clave Valor) { return BuscarRama(Raiz, Valor); }
    //void Insertar(Clave Valor) { InsertarRama(Raiz, Valor); }
    //void Eliminar(Clave Valor) { EliminarRama(Raiz, Valor); }

    /*
    void write(ostream &os)
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

public:
    bool buscarRama(nodoBB<Clave> *Nodo, Clave Valor)
    {
        if (Nodo == NULL)
            return false;
        if (Nodo->Dato == Valor)
            return true;
        if (Nodo->Dato < Valor)
        {
            nodoBB<Clave> *Izq_;
            Izq_ = new nodoBB<Clave>(Nodo->Izq->Dato);
            BuscarRama(Izq_, Valor);
        }
        nodoBB<Clave> *Der_;
        Der_ = new nodoBB<Clave>(Nodo->Der->Dato);
        BuscarRama(Der_, Valor);
    }

    void insertarRama(nodoBB<Clave> *Nodo, Clave Valor)
    {

        if (Nodo == NULL)
        {
            Nodo = new nodoBB<Clave>(Valor);
        }
        else if (Valor < Nodo->Dato)
        {
            nodoBB<Clave> *Izq_;
            Izq_ = new nodoBB<Clave>(Nodo->Izq->Dato);
            InsertarRama(Izq_, Valor);
        }
        else
        {
            nodoBB<Clave> *Der_;
            Der_ = new nodoBB<Clave>(Nodo->Der->Dato);
            InsertarRama(Der_, Valor);
        }
        cout << "Valor: " << Valor.get_DNI() << endl;
    }

    void eliminarRama(nodoBB<Clave> *Nodo, Clave Valor)
    {
        if (Nodo == NULL)
            return;
        if (Valor < Nodo->Dato)
        {
            nodoBB<Clave> *Izq_;
            Izq_ = new nodoBB<Clave>(Nodo->Izq->Dato);
            EliminarRama(Izq_, Valor);
        }
        else if (Valor > Nodo->Dato)
        {
            nodoBB<Clave> *Der_;
            Der_ = new nodoBB<Clave>(Nodo->Der->Dato);
            EliminarRama(Der_, Valor);
        }
        else
        {
            nodoBB<Clave> *Eliminado = Nodo;
            nodoBB<Clave> *Der_, *Izq_;
            Der_ = new nodoBB<Clave>(Nodo->Der->Dato);
            Izq_ = new nodoBB<Clave>(Nodo->Izq->Dato);
            if (Der_ == NULL)
                Nodo = Izq_;
            else if (Izq_ == NULL)
                Nodo = Der_;
            else
                Sustituye(Eliminado, Izq_);
            delete (Eliminado);
        }
    }

    void sustituye(nodoBB<Clave> *Eliminado, nodoBB<Clave> *Sustituto)
    {
        nodoBB<Clave> *Der_, *Izq_;
        Der_ = new nodoBB<Clave>(Sustituto->Der->Dato);
        Izq_ = new nodoBB<Clave>(Sustituto->Izq->Dato);
        if (Der_ != NULL)
            Sustituye(Eliminado, Der_);
        else
        {
            // Eliminado->Get_Dato() = Sustituto->Get_Dato();
            Eliminado = Sustituto;
            Sustituto = Izq_;
        }
    }

    void recorrer(std::ostream &os, nodoBB<Clave> *Nodo, int i)
    {
        nodoBB<Clave> *Der_, *Izq_;
        Der_ = new nodoBB<Clave>(Nodo->Der->Dato);
        Izq_ = new nodoBB<Clave>(Nodo->Izq->Dato);
        os << "Nivel " << i << ": [" << Nodo->Dato << "] ";

        if (Izq_ != NULL)
        {
            Recorrer(os, Izq_, i++);
        }

        if (Der_ != NULL)
        {
            Recorrer(os, Der_, i++);
        }
    }
    */
};