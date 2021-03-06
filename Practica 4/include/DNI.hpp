#pragma once
#include <cstdlib>
#include <iostream>
#include "Contador.hpp"
#include <string.h>

const int DNI_SIZE = 10000;
const int LETTER_SZ = 100;

class DNI
{

private:
    unsigned long Dni_;
    std::string Matricula;
    int valor_;
    int Size_;
    std::string numeros = "0123456789";
    std::string letrasma = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    static Contador cont;
    static Contador Max;
    static Contador Min;
    static Contador Iter;

    DNI();
    DNI(int seed);
    ~DNI();

    inline unsigned long val() { return Dni_; }
    inline std::string matr() { return Matricula; }

    inline int value() const { return valor_; }
    inline void value(int value) { valor_ = value; }
    inline int count_Search() const { return DNI::cont.Get(); }
    static void reset();

    inline void set_none(void) { Dni_ = -1; }
    inline int length() { return Size_; }

    operator unsigned long() const;
    bool operator==(const DNI R_value);
    bool operator<=(const DNI R_value);
    bool operator>=(const DNI R_value);
    bool operator!=(const DNI R_value);
    bool operator>(const DNI R_value);
    bool operator<(const DNI R_value);
};