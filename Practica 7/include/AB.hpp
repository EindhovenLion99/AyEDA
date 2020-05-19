#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include "nodoB.hpp"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

template <class Clave>
class AB
{
private:
    nodoAVL<Clave> *Raiz;

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

    void Insertar(Clave Valor)
    {
        if (!Buscar(Valor))
            InsertarRama(Valor, Raiz);
        else
            cout << red << " ** Valor ya insertado **\n"
                 << white << endl;
    }

    void InsertarAVL(Clave Valor)
    {
        nodoAVL<Clave> Nuevo = nodoAVL<Clave>(Valor);
        bool Crece = false;
        Inserta_Bal(Raiz, Nuevo, Crece);
    }

    void Inserta_Bal(nodoAVL<Clave> *&Nodo, nodoAVL<Clave> *&Nuevo, bool &Crece)
    {
        if (Nodo == nullptr)
        {
            Nodo = Nuevo;
            Crece = true;
        }
        else if (Nuevo->Dato < Nodo->Dato)
        {
            Inserta_Bal(Nodo->Izq, Nuevo, Crece);
            if (Crece)
                Insert_Re_Balancea_Izq(Nodo, Crece);
        }
        else
        {
            Inserta_Bal(Nodo->Der, Nuevo, Crece);
            if (Crece)
                Insert_Re_Balancea_Der(Nodo, Crece);
        }
    }

    void Insert_Re_Balancea_Izq(nodoAVL<Clave> *&Nodo, bool &Crece)
    {
        switch (Nodo->Bal)
        {
        case -1:
        {

            Nodo->Bal = 0;
            Crece = false;
            break;
        }
        case 0:
        {
            Nodo->Bal = 1;
            break;
        }
        case 1:
        {
            nodoAVL<Clave> *Nodo1 = Nodo->Izq;
            if (Nodo1->Bal == 1)
                RotacionII(Nodo);
            else
                RotacionID(Nodo);
            Crece = false;
            break;
        }
        default:
            cout << "Switch fail" << endl;
            break;
        }
    }

    void Insert_Re_Balancea_Der(nodoAVL<Clave> *&Nodo, bool &Crece)
    {
        switch (Nodo->Bal)
        {
        case -1:
        {

            Nodo->Bal = 0;
            Crece = false;
            break;
        }
        case 0:
        {
            Nodo->Bal = -1;
            break;
        }
        case 1:
        {

            nodoAVL<Clave> *Nodo1 = Nodo->Der;
            if (Nodo1->Bal == -1)
                RotacionDD(Nodo);
            else
                RotacionDI(Nodo);
            Crece = false;
            break;
        }
        default:
            cout << "Switch fail" << endl;
            break;
        }
    }

    void Eliminar(Clave Valor)
    {
        EliminarRama(Valor, Raiz);
    }

    void EliminarAVL(Clave Valor)
    {
        bool Decrece = false;
        Eliminar_Rebal(Raiz, Valor, Decrece);
    }

    void Eliminar_Rebal(nodoAVL<Clave> *&Nodo, Clave Valor, bool &Decrece)
    {
        if (Nodo == nullptr)
            return;
        if (Valor < Nodo->Dato)
        {
            Eliminar_Rebal(Nodo->Izq, Valor, Decrece);
            if (Decrece)
                Eliminar_Re_Balancea_Izq(Nodo, Decrece);
        }
        else if (Valor > Nodo->Dato)
        {
            Eliminar_Rebal(Nodo->Der, Valor, Decrece);
            if (Decrece)
                Eliminar_Re_Balancea_Der(Nodo, Decrece);
        }
        else
        {
            nodoAVL<Clave> *Eliminado = Nodo;
            if (Nodo->Izq == nullptr)
            {
                Nodo = Nodo->Der;
                Decrece = true;
            }
            else if (Nodo->Der == nullptr)
            {
                Nodo = Nodo->Izq;
                Decrece = true;
            }
            else
            {
                SustituyeAVL(Eliminado, Nodo->Izq, Decrece);
                if (Decrece)
                    Eliminar_Re_Balancea_Izq(Nodo, Decrece);
            }
            delete Eliminado;
        }
    }

    void SustituyeAVL(nodoAVL<Clave> *&Eliminado, nodoAVL<Clave> *&Sustituto, bool &Decrece)
    {
        if (Sustituto->Der != NULL)
        {
            SustituyeAVL(Eliminado, Sustituto->Der, Decrece);
            if (Decrece)
                Eliminar_Re_Balancea_Der(Sustituto, Decrece);
        }
        else
        {
            Eliminado->Dato = Sustituto->Dato;
            Eliminado = Sustituto;
            Sustituto = Sustituto->Izq;
            Decrece = true;
        }
    }

    void Eliminar_Re_Balancea_Izq(nodoAVL<Clave> *&Nodo, bool &Decrece)
    {
        switch (Nodo->Bal)
        {
        case -1:
        {

            nodoAVL<Clave> *Nodo1 = Nodo->Der;
            if (Nodo1->Bal > 0)
                RotacionDI(Nodo);
            else
            {
                if (Nodo1->Bal == 0)
                    Decrece = false;
                RotacionDD(Nodo);
            }
            break;
        }
        case 0:
        {

            Nodo->Bal = -1;
            Decrece = false;
            break;
        }
        case 1:
        {
            Nodo->Bal = 0;
        }
        }
    }

    void Eliminar_Re_Balancea_Der(nodoAVL<Clave> *&Nodo, bool &Decrece)
    {
        switch (Nodo->Bal)
        {
        case -1:
        {

            nodoAVL<Clave> *Nodo1 = Nodo->Izq;
            if (Nodo1->Bal < 0)
                RotacionID(Nodo);
            else
            {
                if (Nodo1->Bal == 0)
                    Decrece = false;
                RotacionII(Nodo);
            }
            break;
        }
        case 0:
        {

            Nodo->Bal = 1;
            Decrece = false;
            break;
        }
        case 1:
        {
            Nodo->Bal = 0;
        }
        }
    }

    const bool Equilibrado() { return EquilibrioRama(Raiz); }

    bool BuscarRama(Clave Valor, nodoAVL<Clave> *&Nodo)
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

    void InsertarRama(Clave Valor, nodoAVL<Clave> *&Nodo)
    {

        if (Nodo == NULL)
        {
            Nodo = new nodoAVL<Clave>(Valor);
        }
        else if (Valor < Nodo->Dato)
        {
            InsertarRama(Valor, Nodo->Izq);
        }
        else if (Valor > Nodo->Dato)
        {
            InsertarRama(Valor, Nodo->Der);
        }
    }

    void EliminarRama(Clave Valor, nodoAVL<Clave> *&Nodo)
    {
        if (Nodo == NULL)
            return;
        if (Valor < Nodo->Dato)
        {
            EliminarRama(Valor, Nodo->Izq);
        }
        else if (Valor > Nodo->Dato)
        {
            EliminarRama(Valor, Nodo->Der);
        }
        else
        {
            nodoAVL<Clave> *Eliminado = Nodo;
            if (Nodo->Der == NULL)
                Nodo = Nodo->Izq;
            else if (Nodo->Izq == NULL)
                Nodo = Nodo->Der;
            else
                Sustituye(Eliminado, Nodo->Izq);
            delete (Eliminado);
        }
    }

    void Sustituye(nodoAVL<Clave> *&Eliminado, nodoAVL<Clave> *&Sustituto)
    {
        if (Sustituto->Der != NULL)
            Sustituye(Eliminado, Sustituto->Der);
        else
        {
            Eliminado->Dato = Sustituto->Dato;
            Eliminado = Sustituto;
            Sustituto = Sustituto->Izq;
        }
    }

    void Write()
    {
        RecorrerN(Raiz);
    }

    void RecorrerN(nodoAVL<Clave> *Nodo)
    {
        deque<pair<nodoAVL<Clave> *, int>> Q;              // Cola para guardar los nodos por niveles
        nodoAVL<Clave> *aux;                               // Nodo auxiliar
        int Nivel = 0;                                     // Nivel auxiliar
        int Nivel_Actual = 0;                              // Nivel actual
        Q.push_back(pair<nodoAVL<Clave> *, int>(Nodo, 0)); // Se inserta el primer nodo y nivel (nodo raíz y nivel 0)
        cout << "Nivel 0: ";

        while (!Q.empty())
        {
            aux = Q.front().first;
            Nivel = Q.front().second;
            Q.pop_front();
            if (Nivel > Nivel_Actual)
            {
                Nivel_Actual = Nivel;
                cout << "\nNivel " << Nivel_Actual << ": ";
            }
            Imprimir(aux);
            if (aux != nullptr)
            {
                Q.push_back(pair<nodoAVL<Clave> *, int>(aux->Izq, Nivel + 1));
                Q.push_back(pair<nodoAVL<Clave> *, int>(aux->Der, Nivel + 1));
            }
        }
        cout << endl;
    }

    void Imprimir(nodoAVL<Clave> *Nodo)
    {
        if (Nodo == nullptr)
            cout << "[.]";
        else
        {
            cout << "[";
            Nodo->Dato.Print(cout);
            cout << "]";
        }
    }

    const int TamRama(nodoAVL<Clave> *Nodo)
    {
        if (Nodo == nullptr)
            return 0;
        return (1 + TamRama(Nodo->Izq) + TamRama(Nodo->Der));
    }

    const bool EquilibrioRama(nodoAVL<Clave> *Nodo)
    {
        if (Nodo == nullptr)
            return true;
        int eq = (TamRama(Nodo->Izq) - TamRama(Nodo->Der));
        switch (eq)
        {
        case -1:
        case 0:
        case 1:
            return EquilibrioRama(Nodo->Izq) &&
                   EquilibrioRama(Nodo->Der);
        default:
            return false;
        }
    }

    void RotacionII(nodoAVL<Clave> *&Nodo)
    {
        nodoAVL<Clave> *Nodo1 = Nodo->Izq;
        Nodo->Izq = Nodo1->Der;
        Nodo1->Der = Nodo;
        if (Nodo1->Bal == 1)
        {
            Nodo->Bal = 0;
            Nodo1->Bal = 0;
        }
        else
        { // Nodo1->bal == 0
            Nodo->Bal = 1;
            Nodo1->Bal = -1;
        }
        Nodo = Nodo1;
    }

    void RotacionDD(nodoAVL<Clave> *&Nodo)
    {
        nodoAVL<Clave> *Nodo1 = Nodo->Der;
        Nodo->Der = Nodo1->Izq;
        Nodo1->Izq = Nodo;
        if (Nodo1->Bal == -1)
        {
            Nodo->Bal = 0;
            Nodo1->Bal = 0;
        }
        else
        { // Nodo1->bal == 0
            Nodo->Bal = -1;
            Nodo1->Bal = 1;
        }
        Nodo = Nodo1;
    }

    void RotacionID(nodoAVL<Clave> *&Nodo)
    {
        nodoAVL<Clave> *Nodo1 = Nodo->Izq;
        nodoAVL<Clave> *Nodo2 = Nodo1->Der;
        Nodo->Izq = Nodo2->Der;
        Nodo2->Der = Nodo;
        Nodo1->Der = Nodo2->Izq;
        Nodo2->Izq = Nodo1;
        if (Nodo2->Bal == -1)
            Nodo1->Bal = 1;
        else
            Nodo1->Bal = 0;
        if (Nodo2->Bal == 1)
            Nodo->Bal = -1;
        else
            Nodo->Bal = 0;
        Nodo2->Bal = 0;
        Nodo = Nodo2;
    }

    void RotacionDI(nodoAVL<Clave> *&Nodo)
    {
        nodoAVL<Clave> *Nodo1 = Nodo->Der;
        nodoAVL<Clave> *Nodo2 = Nodo1->Izq;
        Nodo->Der = Nodo2->Izq;
        Nodo2->Izq = Nodo;
        Nodo1->Izq = Nodo2->Der;
        Nodo2->Der = Nodo1;
        if (Nodo2->Bal == 1)
            Nodo1->Bal = -1;
        else
            Nodo1->Bal = 0;
        if (Nodo2->Bal == -1)
            Nodo->Bal = 1;
        else
            Nodo->Bal = 0;
        Nodo2->Bal = 0;
        Nodo = Nodo2;
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
};

// Arbol AVL

template <class Clave>
class AVL : public AB<Clave>
{
public:
    AVL() : AB<Clave>()
    {
    }
    ~AVL(){};
};