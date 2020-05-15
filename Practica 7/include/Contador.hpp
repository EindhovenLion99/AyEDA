#pragma once

#define MAX 999999

using namespace std;

class Contador
{

public:
    int Min;
    int Max;
    int Medio;
    int Acumulador;
    int NumP;

public:
    Contador()
    {
        Reset();
    }
    ~Contador() {}

    void Reset()
    {
        Min = MAX;
        Max = 0;
        Medio = 0;
        Acumulador = 0;
        NumP = 0;
    }

    void Start()
    {
        Acumulador = 0;
    }

    void End()
    {
        // cout << "Mínimo: " << min << endl;
        // cout << "Máximo: " << max << endl;

        Min = (Acumulador < Min) ? Acumulador : Min;
        Max = (Acumulador > Max) ? Acumulador : Max;
        Medio += Acumulador;
        NumP++;
    }

    int operator++()
    {
        // cout << "Estoy por aquí, con valor: " << acumulador << endl;
        Acumulador++;
        return Acumulador;
    }

    int getMin()
    {
        return Min;
    }

    int getMax()
    {
        return Max;
    }

    int getMedio()
    {
        return Medio / NumP;
    }

    void Show()
    {
        cout << "Mínimo: " << Min << endl;
        cout << "Máximo: " << Max << endl;
        cout << "Medio: " << Medio / NumP << endl;
    }
};