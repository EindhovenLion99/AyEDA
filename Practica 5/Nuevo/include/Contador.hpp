#pragma once

class Contador
{
private:
    int Valor_;

public:
    Contador() : Valor_(0) {}
    ~Contador() {}

    inline int get_Cont() { return Valor_; }
    inline void Suma() { Valor_++; }
    inline void Resta() { (Valor_ > 0) ? Valor_-- : Valor_ = 0; }
    inline void Reset() { Valor_ = 0; }
};