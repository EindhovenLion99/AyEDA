#include "H.hpp"

template <class Clave> class H_Pseudoaleatoria : public H<Clave> {

    public:
        H_Pseudoaleatoria(){H<Clave>::cadena="Pseudoaleatorio";}
        int operator()(Clave&, int);

};

template <class Clave>
int H_Pseudoaleatoria<Clave>::operator()(Clave& x, int sz) {
    srand(x.get_value());
    return rand() % sz;
}