#include "G.hpp"

template <class Clave> class G_Lineal : public G <Clave> {
    public:
        G_Lineal(){G<Clave>::cadena="Lineal";};
        virtual ~G_Lineal(){};
        int operator()(Clave&, int, int);
};
template<class Clave>
int G_Lineal<Clave>::operator()(Clave& x, int att, int nCeldas) {
    return ((att)%nCeldas);
}