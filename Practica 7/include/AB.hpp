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
    void Eliminar(Clave Valor) { EliminarRama(Valor, Raiz); }
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

    void Write(ostream &os)
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
        nodoAVL Nodo1 = Nodo->Izq;
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
        nodoAVL Nodo1 = Nodo->Der;
        Nodo->Der = Nodo1->Izq;
        Nodo1->Izq = nodo;
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
        nodoAVL *Nodo1 = Nodo->Izq;
        nodoAVL *Nodo2 = Nodo1->Der;
        Nodo->Izq = Nodo2->Der;
        Nodo2->Der = Nodo;
        Nodo1->Der = Nodo2->Izq;
        Nodo2->Izq = Nodo1;
        if (Nodo2->Bal == -1)
            Nodo1->Bal = 1;
        else
            Nodo1->Bal = 0;
        if (Nodo2->Bal == 1)
            Nodo->Bal = -1 else Nodo->Bal = 0;
        Nodo2->Bal = 0;
        Nodo = Nodo2;
    }

    void RotacionDI(nodoAVL<Clave> *&Nodo)
    {
        nodoAVL *Nodo1 = Nodo->Der;
        nodoAVL *Nodo2 = Nodo1->Izq;
        Nodo->Der = Nodo2->Izq;
        Nodo2->Izq = Nodo;
        Nodo1->Izq = Nodo2->Der;
        Nodo2->dcho = Nodo1;
        if (Nodo2->Bal == 1)
            Nodo1->Bal = -1;
        else
            Nodo1->Bal = 0;
        if (Nodo2->Bal == -1)
            Nodo->Bal = 1 else Nodo->Bal = 0;
        Nodo2->Bal = 0;
        Nodo = Nodo2;
    }

    void InsertarAVL(Clave Valor)
    {
        nodoAVL Nuevo = nodoAVL(Valor);
        bool Crece = false;
        Inserta_Bal(Raiz, Nuevo, Crece);
    }

    void Inserta_Bal(nodoAVL<Clave> *&Nodo, nodoAVL<Clave> *Nuevo, bool &Crece)
    {
        if (Nodo == NULL)
        {
            Nodo = Nuevo;
            Crece = true;
        }
        else if (Nuevo->Dato < Nodo->Dato)
        {
            Inserta_Bal(Nodo->Izq, Nuevo, Crece);
            if (Crece)
                Insert_ReBalanceaIzq(Nodo);
        }
        else
        {
            Inserta_Bal(Nodo->Der, Nuevo, Crece);
            if (crece)
                Insert_ReBalanceaDer(Nodo);
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