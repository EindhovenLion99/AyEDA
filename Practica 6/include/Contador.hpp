#pragma once
#include <limits>

class Contador
{
private:
    int Accum;
    int Max;
    int Min;
    int LocalAccum;

public:
    Contador(){};
    void Starting()
    {
        LocalAccum = 0;
        Max = 0;
        Min = 100000000;
        Accum = 0;
    };
    void Calculate()
    {
        Min = LocalAccum < Min ? LocalAccum : Min;
        Max = LocalAccum > Max ? LocalAccum : Max;
        Accum += LocalAccum;
    };
    Contador &operator++(int)
    {
        LocalAccum++;
        return *this;
    };

    int getAccum() { return Accum; };
    int getMax() { return Max; };
    int getMin() { return Min; };
    int getMedia() { return ((Max + Min) / 2); };
};