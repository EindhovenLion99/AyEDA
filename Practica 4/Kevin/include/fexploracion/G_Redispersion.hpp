#include "G.hpp"

template <class Clave> class G_Redispersion : public G <Clave>{
public:
    G_Redispersion(){G<Clave>::cadena="Redispersion";};
    int operator()(Clave&, int, int);
};
template<class Clave>
int G_Redispersion<Clave>::operator()(Clave& x, int att, int nCeldas) {
    return ((rand()+att)%nCeldas);
}
