#include <iostream>
#include "vector_t.hpp"
#include "DNI.hpp"
#include "Insercion.hpp"
#include "Burbuja.hpp"
#include "Heap.hpp"
#include "Quick.hpp"
#include "Shell.hpp"
#include "termcolor.hpp"

using namespace termcolor;
using namespace std;

void Print_Array(Vector_T<DNI> &V, bool sorted);
void Print_Ar(Vector_T<int> &V, bool sorted);
void Filling(Vector_T<DNI> &V);

int main()
{

    bool sorted = false;
    int opc;

    cout << white << "Elige el metodo de ordenacion (1...5): ";
    cin >> opc;
    int c = getchar();

    Vector_T<DNI> Array(10, 1);
    Vector_T<int> Ar(14, 1);

    //13 3 4 12 14 10 5 1 8 2 7 9 11 6
    Ar[1] = 13;
    Ar[2] = 3;
    Ar[3] = 4;
    Ar[4] = 12;
    Ar[5] = 14;
    Ar[6] = 10;
    Ar[7] = 5;
    Ar[8] = 1;
    Ar[9] = 8;
    Ar[10] = 2;
    Ar[11] = 7;
    Ar[12] = 9;
    Ar[13] = 11;
    Ar[14] = 6;

    Filling(Array);

    cout << endl;
    Print_Array(Array, sorted);

    switch (opc)
    {

    case 1:
        Insercion<DNI>(Array, Array.size());
        sorted = true;
        cout << "OK" << endl;
        Print_Array(Array, sorted);
        break;
    case 2:

        Burbuja<DNI>(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        break;
    case 3:

        Quick<DNI>(Array, Array.start(), Array.end());
        sorted = true;
        Print_Array(Array, sorted);
        break;

    case 4:
        Heap<DNI>(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        break;
    case 5:
        Shell<DNI>(Array, Array.size());
        sorted = true;
        Print_Array(Array, sorted);
        sorted = false;
        Print_Ar(Ar, sorted);
        Shell(Ar, Ar.size());
        sorted = true;
        Print_Ar(Ar, sorted);
        break;

    default:
        break;
    }
}

void Print_Array(Vector_T<DNI> &V, bool sorted)
{

    if (sorted)
        cout << yellow << "Sorted: ";
    else
        cout << yellow << "Unsorted: ";

    for (int i = V.start(); i <= V.end(); i++)
    {
        if (sorted)
            cout << red << V[i] << " ";
        else
            cout << green << V[i] << " ";
    }
    cout << endl
         << endl;
}

void Print_Ar(Vector_T<int> &V, bool sorted)
{

    if (sorted)
        cout << yellow << "Sorted: ";
    else
        cout << yellow << "Unsorted: ";

    for (int i = V.start(); i <= V.end(); i++)
    {
        if (sorted)
            cout << red << V[i] << " ";
        else
            cout << green << V[i] << " ";
    }
    cout << endl
         << endl;
}

void Filling(Vector_T<DNI> &V)
{
    srand(time(NULL));
    for (int i = V.start(); i <= V.end(); i++)
    {
        DNI Num;
        V[i] = Num;
    }
}