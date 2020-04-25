#include "H.hpp"

template <class Clave>
class H_Suma : public H<Clave>
{

  public:
    H_Suma() { H<Clave>::cadena = "Suma"; }
    int operator()(Clave &x, int limite);
};

template <class Clave>
int H_Suma<Clave>::operator()(Clave &x, int limite)
{
    unsigned int d = 0;
    unsigned int ccopy = x.get_value();
    while (ccopy != 0)
    {
        d += ccopy % 10;
        ccopy /= 10;
    }
    return d % limite;
}

