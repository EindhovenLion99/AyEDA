#include <iostream>
#include "termcolor.hpp"
#include "AB.hpp"
#include "nodoB.hpp"
#include "DNI.hpp"

using namespace std;
using namespace termcolor;

// Funciones

template <class Clave>
void Buscar(AB<Clave> Arbol);

template <class Clave>
void Insertar(AB<Clave> Arbol);

template <class Clave>
void Eliminar(AB<Clave> Arbol);

// Modos

template <class Clave>
void ModoDemo(AB<Clave> Arbol)
{
    int Opc;

    cout << "Insertar (1)" << endl;
    cout << "Eliminar (2)" << endl;
    cout << "Selecciona una opcion: ";
    cin >> Opc;

    switch (Opc)
    {
    case 1:
        Insertar(Arbol);
        break;

    case 2:
        //Eliminar(Arbol);
        break;

    default:
        break;
    }
}

template <class Clave>
void ModoEstad(AB<Clave> Arbol)
{
}

int main()
{
    cout << yellow << "Practica 6: Arbol Binario de Busqueda" << endl;
    AB<DNI> Arbol;

    int Opc;

    cout << "Modo Demostracion (1)" << endl;
    cout << "Modo Estadistico (2)" << endl;
    cout << "Selecciona una opcion: ";
    cin >> Opc;

    switch (Opc)
    {
    case 1:
        ModoDemo(Arbol);
        break;
    case 2:
        // ModoEstad(Arbol);
        break;
    default:
        cout << "Escoga la opcion adecuada" << endl;
        break;
    }
}

/*
template <class Clave>
void Buscar(AB<Clave> Arbol)
{
    if (Arbol.isNull())
    {
        cout << "El arbol esta vacio" << endl;
    }
    else
    {
        int Valor;
        DNI Num;
        cout << "Inserte el valor a buscar: ";
        cin >> Valor;
        Num = Valor;
        if (Arbol.Buscar(Num))
        {
            cout << "El valor " << Valor << " se ha encontrado" << endl;
        }
        else
        {
            cout << "El valor " << Valor << " no se ha encontrado" << endl;
        }
    }
}
*/

template <class Clave>
void Insertar(AB<Clave> Arbol)
{
    int Valor;
    DNI Num;
    cout << "Seleccione el valor a insertar: ";
    cin >> Valor;
    Num.Set_Valor(Valor);
    Arbol.Insertar(Num);
    Arbol.Write(cout);
}