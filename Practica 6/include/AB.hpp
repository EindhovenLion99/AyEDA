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
    nodoBB<Clave> *Raiz;

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

    bool BuscarRama(Clave Valor, nodoBB<Clave> *&Nodo)
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

    void InsertarRama(Clave Valor, nodoBB<Clave> *&Nodo)
    {

        if (Nodo == NULL)
        {
            Nodo = new nodoBB<Clave>(Valor);
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

    void EliminarRama(Clave Valor, nodoBB<Clave> *&Nodo)
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
            nodoBB<Clave> *Eliminado = Nodo;
            if (Nodo->Der == NULL)
                Nodo = Nodo->Izq;
            else if (Nodo->Izq == NULL)
                Nodo = Nodo->Der;
            else
                Sustituye(Eliminado, Nodo->Izq);
            delete (Eliminado);
        }
    }

    void Sustituye(nodoBB<Clave> *&Eliminado, nodoBB<Clave> *&Sustituto)
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

    void RecorrerN(nodoBB<Clave> *Nodo)
    {
        deque<pair<nodoBB<Clave> *, int>> Q;              // Cola para guardar los nodos por niveles
        nodoBB<Clave> *aux;                               // Nodo auxiliar
        int Nivel = 0;                                    // Nivel auxiliar
        int Nivel_Actual = 0;                             // Nivel actual
        Q.push_back(pair<nodoBB<Clave> *, int>(Nodo, 0)); // Se inserta el primer nodo y nivel (nodo raíz y nivel 0)
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
                Q.push_back(pair<nodoBB<Clave> *, int>(aux->Izq, Nivel + 1));
                Q.push_back(pair<nodoBB<Clave> *, int>(aux->Der, Nivel + 1));
            }
        }
        cout << endl;
    }

    void Imprimir(nodoBB<Clave> *Nodo)
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