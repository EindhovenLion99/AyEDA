#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Contador.hpp"

using namespace std;

class DNI
{
private:
    int Valor_;
    unsigned long longValue_;

public:
    DNI();
    DNI(int Semilla);
    ~DNI();
    static Contador Cont_;

    inline int get_DNI() const { return Valor_; }
    inline void set_DNI(int val) { Valor_ = val; }

    inline void set_Empty() { Valor_ = -1; }

    ostream &Print(ostream &) const;

    bool operator==(DNI &Val);
    bool operator!=(DNI &Val);
    bool operator>(DNI &Val);
    bool operator<(DNI &Val);
    bool operator<=(DNI &Val);
    bool operator>=(DNI &Val);

    operator unsigned long() const;
    /*
        static void Reset();
    static int get_Cont();
    static void Plus();
    */
};