#pragma once

class contador
{
private:
    int valor;

public:
    contador() : valor(0) {}
    ~contador() {}
    inline void Reset() { valor = 0; }
    inline void Inc() { valor++; }
    inline void Dec() { (valor > 0) ? valor-- : valor = 0; }
    inline int Get() { return valor; }
};
