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
    int Sz_;

public:
    DNI();
    ~DNI();
    static Contador Cont_;

    inline int get_DNI() const { return Valor_; }
    inline int get_Sz() const { return Sz_; }
    inline void set_DNI(int val) { Valor_ = val; }

    inline void set_Empty() { Valor_ = -1; }
    DNI &operator=(DNI &);

    ostream &Print(ostream &) const;
    void Set_Valor(int Valor);

    bool operator==(const DNI &Val);
    bool operator>(const DNI &Val);
    bool operator<(const DNI &Val);

    operator unsigned long() const;
    /*
    static void Reset();
    static int get_Cont();
    static void Plus();
    */
};