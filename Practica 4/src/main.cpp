#include <iostream>
#include <cstdlib>
#include "Tabla.hpp"
#include "DNI.hpp"
#include "Celda.hpp"
#include <vector>

using namespace std;

void Banco(vector<DNI> &Claves, int Sz);

int main()
{
    srand(time(NULL));

    int celda, bloque, fd, fe;
    double factor, relleno;

    cout << "Introduzca numero de celdas: ";
    cin >> celda;
    cout << "Introduzca numero de bloques: ";
    cin >> bloque;
    cout << "Introduzca funcion de dispersion: ";
    cin >> fd;
    cout << "Introduzca funcion de exploracion: ";
    cin >> fe;
    cout << "Introduzca % (0.X) de relleno: ";
    cin >> relleno;

    Tabla<DNI> Tab(celda, bloque, fd, fe);

    factor = celda * bloque * relleno;
    int Size = 2 * int(factor);

    vector<DNI> Claves;
    Banco(Claves, Size);

    for (int i = 0; i < factor; i++)
        Tab.Insert_T(Claves[i]);

    //Tab.Write(std::cout);

    cout << "Celdas\tClaves\tDisp\tExp\tCarga\tPruebas" << endl;
    cout << celda << "\t" << 2 * int(factor) << "\t" << fd << "\t" << fe << "\t" << relleno << "\t" << factor << endl;
    cout << endl;
    cout << "\t\tMaximo\tMedio\tMinimo" << endl;

    int Max = 0;
    int Min = 100000000;
    int Med = 0;

    DNI::cont.reset();

    for (int i = 0; i < factor; i++)
    {
        Tab.Search_T(Claves[i]);
        if (DNI::cont.Get() > Max)
            Max = DNI::cont.Get();
        if (DNI::cont.Get() < Min)
            Min = DNI::cont.Get();
        Med += DNI::cont.Get();
    }
    Med = Med / int(factor);

    cout << "Busquedas\t" << Max << "\t" << Med << "\t" << Min;

    cout << endl;
    DNI::cont.reset();

    Max = 0;
    Min = 100000000;
    Med = 0;

    for (int i = factor; i < Size; i++)
    {
        Tab.Search_T(Claves[i]);
        if (DNI::cont.Get() > Max)
            Max = DNI::cont.Get();
        if (DNI::cont.Get() < Min)
            Min = DNI::cont.Get();
        Med += DNI::cont.Get();
    }
    cout << "Inserccion\t" << Max << "\t" << Med / int(factor) << "\t" << Min;
    cout << endl;
}

void Banco(vector<DNI> &Claves, int Sz)
{
    for (int i = 0; i < Sz; i++)
    {
        DNI Clave;
        Claves.push_back(Clave);
    }
}
