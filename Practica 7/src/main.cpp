#include <iostream>
#include <vector>
#include "termcolor.hpp"
#include "AB.hpp"
#include "nodoB.hpp"
#include "DNI.hpp"

using namespace std;
using namespace termcolor;

// Modos

template <class Clave>
void ModoDemo(ABB<Clave> Arbol)
{
    int Opc = 1;
    int Valor = 0;

    while (Opc != 0)
    {
        cout << endl
             << blue << "Salir (0)" << endl;
        cout << "Insertar (1)" << endl;
        cout << "Eliminar (2)" << endl;
        cout << "Comprobar equilibrado (3)" << endl;
        cout << "Selecciona una opcion: ";
        cin >> Opc;
        switch (Opc)
        {
        case 1:
        {
            cout << endl;
            cout << green << "Seleccione el valor a insertar: " << white;
            cin >> Valor;
            cout << endl;
            DNI Num(Valor);
            Arbol.Insertar(Num);
            Arbol.Write(cout);
            break;
        }
        case 2:
        {
            cout << endl;
            cout << green << "Seleccione el valor a eliminar: " << white;
            cin >> Valor;
            cout << endl;
            DNI Num(Valor);
            Arbol.Eliminar(Num);
            Arbol.Write(cout);
            break;
        }
        case 3:
        {
            if (Arbol.Equilibrado())
            {
                cout << endl;
                Arbol.Write(cout);
                cout << white << endl
                     << "El arbol esta equilibrado" << endl;
            }
            else
            {
                cout << endl;
                Arbol.Write(cout);
                cout << white << endl
                     << "El arbol no esta equilibrado" << endl;
            }
            break;
        }
        case 0:
            cout << "Saliendo" << endl
                 << endl;
            break;
        default:
            cout << "Escoga la opcion adecuada" << endl;
            break;
        }
    }
}

void ModoEstad()
{
    cout << blue << endl
         << "Modo Estadistica" << endl
         << endl;
    cout << blue << "Introduzca el tamaño del arbol: ";
    int N;
    cin >> N;
    cout << blue << "Introduzca el numero de pruebas: ";
    int nPruebas;
    cin >> nPruebas;

    if (nPruebas > N)
    {
        cerr << red << "\nEl número de pruebas no puede ser mayor que el tamaño del árbol\n"
             << endl;
    }
    else
    {
        vector<DNI> Banco;
        ABB<DNI> Arbol;
        for (unsigned j = 0; j < 2 * N; j++)
        {
            DNI X;
            Banco.push_back(X);
        }
        for (unsigned i = 0; i < N; i++)
        {
            Arbol.Insertar(Banco[i]);
        }
        cout << "\n\t\tN\tnPruebas\tMínimo\tMedio\tMáximo" << endl;

        DNI::Cont.Reset();

        for (unsigned i = 0; i < N; i++)
        {
            DNI::Cont.Start();
            Arbol.Buscar(Banco[i]);
            DNI::Cont.End();
        }

        cout << "Búsqueda: "
             << "\t" << N << "\t" << nPruebas << "\t\t" << DNI::Cont.getMin() << "\t";
        cout << DNI::Cont.getMedio() << "\t" << DNI::Cont.getMax() << endl;

        DNI::Cont.Reset();

        for (unsigned i = N; i < 2 * N; i++)
        {
            DNI::Cont.Start();
            Arbol.Buscar(Banco[i]);
            DNI::Cont.End();
        }

        cout << "Insercion: "
             << "\t" << N << "\t" << nPruebas << "\t\t" << DNI::Cont.getMin() << "\t";
        cout << DNI::Cont.getMedio() << "\t" << DNI::Cont.getMax() << endl
             << endl;
    }
}

int main()
{
    cout << yellow << "Practica 7: Arbol AVL" << white << endl;
    ABB<DNI> Arbol;

    int Opc = 1;

    while (Opc != 0)
    {
        cout << yellow << "Salir (0)" << endl;
        cout << yellow << "Modo Demostracion (1)" << endl;
        cout << yellow << "Modo Estadistico (2)" << endl;
        cout << yellow << "Selecciona una opcion: " << white;
        cin >> Opc;
        switch (Opc)
        {
        case 1:
            ModoDemo(Arbol);
            break;
        case 2:
            ModoEstad();
            break;
        case 0:
            cout << "Saliendo" << endl
                 << endl;
            break;
        default:
            cout << "Escoga la opcion adecuada" << endl;
            break;
        }
    }
}
