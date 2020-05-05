#include <iostream>
#include "termcolor.hpp"
#include "ArbolBB.hpp"
#include "nodoBB.hpp"
#include "DNI.hpp"

using namespace std;
using namespace termcolor;

int main()
{
    cout << yellow << "Practica 6: Arbol Binario de Busqueda" << endl;
    ArbolBB<DNI> *Arbol;

    Arbol = new ArbolBB<DNI>;

    Arbol->Write(cout);
    for (int i = 0; i < 5; i++)
    {
        DNI Num;
        Arbol->Insertar(Num);
        Arbol->Write(cout);
    }
}