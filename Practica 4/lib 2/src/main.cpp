#include <iostream>
#include"Tabla.hpp"
using namespace std;

int main()
{
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
    DNI *a[2 * int(factor)];

    cout << "Celdas\tClaves\tDisp\tExp\tCarga\tPruebas" << endl;
    cout << celda << "\t" << 2 * int(factor) << "\t" << fd << "\t" << fe << "\t" << relleno << "\t" << factor << endl;
    cout << endl;
    cout << "\t\tMaximo\tMedio\tMinimo" << endl;
    
    int Max = 0;
    int Min = 100000000;
    int Med = 0;
    int i;
    
   
    for (i = 0; i < int(factor); i++)
    {   cout<<factor<<endl;
        a[i] = new DNI;
        Tab.Insert_T(*a[i]);
        if (DNI::cont.Get() > Max)
            Max = DNI::cont.Get();
        if (DNI::cont.Get() < Min)
            Min = DNI::cont.Get();
        Med += DNI::cont.Get();
    }

    
    cout << "Insertar\t" << Max << "\t" << Med / int(factor) << "\t" << Min;

    cout << endl;
    DNI::cont.reset();
        Max = 0;
        Min = 100000000;
        Med = 0;
    for (; i < 2 * int(factor); i++)
    {
        a[i] = new DNI;
        Tab.Search_T(*a[i]);
        if (DNI::cont.Get() > Max)
            Max = DNI::cont.Get();
        if (DNI::cont.Get() < Min)
            Min = DNI::cont.Get();
        Med += DNI::cont.Get();
    }
    cout << "Buscar\t\t" << Max << "\t" << Med / (2 * int(factor)) << "\t" << Min;
    cout << endl;

}
