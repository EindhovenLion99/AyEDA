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
    DNI(int Num);
    ~DNI();

    inline int get_DNI() const { return Valor_; }
    inline void set_DNI(int val) { Valor_ = val; }

    inline void set_Empty() { Valor_ = -1; }
    DNI &operator=(DNI &);

    static Contador Cont;

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