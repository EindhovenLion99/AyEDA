#include "H.hpp"


template <class Clave> class H_Modulo : public H<Clave> {

    public:
    
        H_Modulo(){H<Clave>::cadena="Modulo";}
        int operator()(Clave&, int);
};


template <class Clave>
int H_Modulo<Clave>::operator()(Clave& x, int sz) {
    return x.get_value()%sz;
}