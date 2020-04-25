#include "G.hpp"


template <class Clave> class G_Cuadratica : public G <Clave> {

public:
    G_Cuadratica(){G<Clave>::cadena="Cuadrática";};
    int operator()(Clave&, int, int);
};

template<class Clave>
int G_Cuadratica<Clave>::operator()(Clave& x, int att, int nCeldas) {
    return ((att*att)%nCeldas);
}

