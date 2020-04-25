#include <iostream>
#include "../include/Celda.hpp"
#include "../include/TablaHash.hpp"
#include "../include/DNI.hpp"
#include "../include/termcolor.hpp"

using namespace termcolor;
using namespace std;

int main(void)
{

    int nCeldas, tBloque, fE, fD; // int g, h;
    double factor;

    TablaHash<DNI> *TH;
    DNI **bench;

    cout << yellow << "Introduzca el número de celdas: " << white;
    cin >> nCeldas;

    cout << yellow << "Introduzca tamaño del bloque: " << white;
    cin >> tBloque;

    cout << yellow << "Introduzca factor de carga: " << white;
    cin >> factor;

    system("clear");

    cout << red << "Selecciona función de dispersión:";
    cout << blue << "\n1. Módulo";
    cout << blue << "\n2. Pseudo-aleatoria";
    cout << blue << "\n3. Suma";
    cout << green << "\nINTRODUZCA OPCIÓN: " << white;
    cin >> fD;

    cout << red << "\nSelecciona función de exploración:";
    cout << blue << "\n1. Lineal";
    cout << blue << "\n2. Cuadrática";
    cout << blue << "\n3. Dispersión";
    cout << green << "\nINTRODUZCA OPCIÓN: " << white;
    cin >> fE;

    TH = new TablaHash<DNI>(nCeldas, tBloque, fE, fD);

    system("clear");

    // Crear un banco de prueba

    int N = (factor * nCeldas * tBloque);
    bench = new DNI *[2 * N];

    for (int i = 0; i < 2 * N; i++)
        bench[i] = new DNI((rand() % 50000000) + 30000000);

    for (int i = 0; i < N; i++)
        TH->Insertar(*bench[i]);

    int comp_total = 0;
    int comp_min = 999999;
    int comp_max = 0;
    int comp_local = 0;

    for (int i = 0; i < N; i++)
    {
        comp_local = 0;
        TH->Buscar(*bench[i], comp_local);
        comp_total += comp_local;

        comp_min = (comp_local < comp_min) ? comp_local : comp_min;
        comp_max = (comp_local > comp_max) ? comp_local : comp_max;
    }

    int comp_total2 = 0;
    int comp_min2 = 999999;
    int comp_max2 = 0;
    int comp_local2 = 0;

    for (int i = N; i < 2 * N; i++)
    {
        comp_local2 = 0;
        TH->Buscar(*bench[i], comp_local2);
        comp_total2 += comp_local2;

        comp_min2 = (comp_local2 < comp_min2) ? comp_local2 : comp_min2;
        comp_max2 = (comp_local2 > comp_max2) ? comp_local2 : comp_max2;
    }

    system("clear");
    TH->Print();
    getchar();
    getchar();

    system("clear");

    cout << blue << "RESULTADOS";
    cout << yellow << "\n____________________________________________\n";
    cout << red << "INFORMACIÓN GENERAL:\n";
    cout << yellow << "Celdas" << setw(10) << "Bloques" << setw(12) << "Dispersion" << setw(15) << "Exploración" << setw(10) << "Carga\n";
    cout << white << nCeldas << setw(12) << tBloque << setw(10) << TH->get_fdisp() << setw(15) << TH->get_fexp() << setw(9) << factor << "\n\n";
    cout << red << "COMPARACIONES: \n";
    cout << yellow << setw(20) << "Mínimo" << setw(10) << "Medio" << setw(10) << "Máximo" << setw(10) << "Total\n";
    cout << yellow << "Busquedas:" << white << setw(7) << comp_min << setw(11) << (comp_min + comp_max) / 2 << setw(8) << comp_max << setw(10) << comp_total << setw(7) << "\n";
    cout << yellow << "Inserción:" << white << setw(7) << comp_min2 << setw(11) << (comp_min2 + comp_max2) / 2 << setw(8) << comp_max2 << setw(10) << comp_total2 << "\n";
}