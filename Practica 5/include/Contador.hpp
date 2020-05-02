#pragma once
#include <limits>

class Contador
{
private:
    int accum;
    int max;
    int min;
    int localAccum;

public:
    Contador(){};
    void start()
    {
        localAccum = 0;
        max = 0;
        min = 100000000;
        accum = 0;
    };
    void stop()
    {
        min = localAccum < min ? localAccum : min;
        max = localAccum > max ? localAccum : max;
        accum += localAccum;
    };
    Contador &operator++(int)
    {
        localAccum++;
        return *this;
    };

    int getAccum() { return accum; };
    int getMax() { return max; };
    int getMin() { return min; };
    int getMedia() { return ((max + min) / 2); };
};