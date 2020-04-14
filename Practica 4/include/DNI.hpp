#pragma once
#include <iostream>
#include <cstdlib>

class contador;
class DNI
{
private:
    int valor;
    unsigned long long_valor;
    int longitud;
    static contador cont;

public:
    DNI();
    ~DNI();

    inline int val() { return valor; }

    static int compara();
    static void reset(void);

    inline void set_none(void) { valor = -1; }
    inline int length() { return longitud; }

    operator unsigned long() const;
    bool operator==(DNI &a);
    bool operator<=(DNI &a);
    bool operator>=(DNI &a);
    bool operator>(DNI &a);
    bool operator<(DNI &a);
    bool operator!=(DNI &a);
};