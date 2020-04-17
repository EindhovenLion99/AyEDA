#pragma once
#include<cstdlib>
#include<iostream>
#include"Contador.hpp"
const int DNI_SIZE = 100000000;

class DNI {

private:
    unsigned long Dni_;
    int valor_;
    int Size_;

public:
    static Contador cont;
    static Contador Max;
    static Contador Min;
    static Contador Iter;

    DNI();
    DNI(int seed);
    ~DNI();

    inline unsigned long val() { return Dni_; }

    inline int value() const { return valor_; }
    inline int count_Search()const {return DNI::cont.Get();}
    static void reset();

    inline void set_none(void) { Dni_ = -1; }
    inline int length() { return Size_; }

    operator unsigned long() const;
    bool operator==(const DNI R_value);
    bool operator<=(const DNI R_value);
    bool operator>=(const DNI R_value);
    bool operator!=(const DNI R_value);
    bool operator> (const DNI R_value);
    bool operator< (const DNI R_value);
};