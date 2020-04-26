#include <iostream>
#include <vector>
#include "DNI.hpp"
#include "Insercion.hpp"
#include "Burbuja.hpp"
#include "Heap.hpp"
#include "Quick.hpp"
#include "Shell.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    vector<DNI> Array;

    for (int i = 0; i < 10; i++)
    {
        DNI Num;
        Array.push_back(Num);
    }

    for (auto i = Array.begin(); i != Array.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;

    for (auto i = Array.begin(); i != Array.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}