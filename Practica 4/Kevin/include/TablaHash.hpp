#include <iostream>
#include <vector>
#include "Celda.hpp"
#include "DNI.hpp"

#include "fexploracion/G_Lineal.hpp"
#include "fexploracion/G_Cuadratica.hpp"
#include "fexploracion/G_Redispersion.hpp"
#include "fdispersion/H_Modulo.hpp"
#include "fdispersion/H_Pseudoaleatoria.hpp"
#include "fdispersion/H_Suma.hpp"

using namespace std;

template <class Clave>
class TablaHash
{
    vector<Celda<Clave>> vCeldas;
    G<Clave> *g_;
    H<Clave> *h_;

public:
    TablaHash(int nCeldas, int nBloques, int g, int h);
    ~TablaHash()
    {
        delete g_;
        delete h_;
    }

    bool Buscar(Clave &);
    bool Insertar(Clave &);
    bool Buscar(Clave &, int &);

    inline string get_fexp(void) { return g_->get_fexp(); }
    inline string get_fdisp(void) { return h_->get_fdisp(); }

    void Print() const;
};

template <class Clave>
TablaHash<Clave>::TablaHash(int nCeldas, int nBloques, int g, int h)
{
    vCeldas.resize(nCeldas);

    for (int i = 0; i < vCeldas.size(); i++)
        vCeldas[i].resize(nBloques);

    switch (g)
    {
    case 1:
        g_ = new G_Lineal<Clave>();
        break;

    case 2:
        g_ = new G_Cuadratica<Clave>();
        break;

    case 3:
        g_ = new G_Redispersion<Clave>();
        break;
    default:
        g_ = new G_Lineal<Clave>();
        break;
    }

    switch (h)
    {
    case 1:
        h_ = new H_Modulo<Clave>();
        break;

    case 2:
        h_ = new H_Pseudoaleatoria<Clave>();
        break;
    case 3:
        h_ = new H_Suma<Clave>();
        break;
    default:
        h_ = new H_Modulo<Clave>();
        break;
    }
}

template <class Clave>
bool TablaHash<Clave>::Insertar(Clave &x)
{
    int hx = (*h_)(x, vCeldas.size());
    int intento = 0;
    int fx = 0;

    while ((!vCeldas[(hx + fx) % vCeldas.size()].insertar(x)) && intento < vCeldas.size())
    {
        intento++;
        fx = (*g_)(x, intento, vCeldas.size());
    }
    return (intento < vCeldas.size());
}

template <class Clave>
bool TablaHash<Clave>::Buscar(Clave &x)
{
    int hx = (*h_)(x, vCeldas.size());
    int intento = 0;
    int fx = 0;

    bool encontrada = false;
    bool Llena = true;
    while ((!encontrada) && intento < vCeldas.size() && Llena)
    {
        encontrada = vCeldas[(hx + fx) % vCeldas.size()].buscar(x);
        Llena = vCeldas[(hx + fx) % vCeldas.size()].esta_llena();
        intento++;
        fx = (*g_)(x, intento, vCeldas.size());
    }
    return encontrada;
}

template <class Clave>
bool TablaHash<Clave>::Buscar(Clave &x, int &cont)
{
    int hx = (*h_)(x, vCeldas.size());
    int intento = 0;
    int fx = 0;

    bool encontrada = false;
    bool Llena = true;
    while ((!encontrada) && intento < vCeldas.size() && Llena)
    {
        encontrada = vCeldas[(hx + fx) % vCeldas.size()].buscar(x, cont);
        Llena = vCeldas[(hx + fx) % vCeldas.size()].esta_llena();
        intento++;
        fx = (*g_)(x, intento, vCeldas.size());
    }
    return encontrada;
}

template <class Clave>
void TablaHash<Clave>::Print() const
{
    for (int i = 0; i < vCeldas.size(); i++)
    {
        vCeldas[i].Print();
        cout << endl;
    }
}
