#pragma once
#include "Celda.hpp"
#include "FDispersionBase.hpp"
#include "FDispersionModulo.hpp"
#include "FDispersionSuma.hpp"
#include "FDispersionPseudoaleatoria.hpp"

#include "FExploracionBase.hpp"
#include "FExploracionCuadratica.hpp"
#include "FExploracionDoble.hpp"
#include "FExploracionLineal.hpp"
#include "FExploracionReDispersion.hpp"

using namespace std;
template <class Clave>
class Tabla
{

private:
    Celda<Clave> **vCelda_;
    int nCeldas_; ////TAMAÑO DE LA TABLA
    int nClaves_;
    FDispersionBase<Clave> *h_;
    FExploracionBase<Clave> *g_;

public:
    Tabla(int nceldas, int nclaves, int Fdisp, int Fexpl);
    ~Tabla();
    bool Search_T(const Clave x);
    bool Insert_T(const Clave &x);

    std::ostream &Write(std::ostream &os);
};

template <class Clave>
Tabla<Clave>::Tabla(int nceldas, int nclaves, int Fdisp, int Fexpl)
{

    nCeldas_ = nceldas;
    nClaves_ = nclaves;
    vCelda_ = new Celda<Clave> *[nCeldas_];
    for (int i = 0; i < nceldas; i++)
    {
        vCelda_[i] = new Celda<Clave>(nclaves);
    }

    switch (Fdisp)
    {
    case 1:
        h_ = new FDispersionModulo<Clave>(nceldas);

        break;
    case 2:
        h_ = new FDispersionSuma<Clave>(nceldas);
        break;
    case 3:
        h_ = new FDispersionPseudoaleatoria<Clave>(nceldas);
        break;
    default:
        cout << "ERROR, FUNCION DE DISPERSION NO VALIDA" << endl;
        break;
    }
    switch (Fexpl)
    {
    case 1:
        g_ = new FExploracionLineal<Clave>(nceldas);

        break;
    case 2:
        g_ = new FExploracionDoble<Clave>(nceldas);
        break;
    case 3:
        g_ = new FExploracionCuadratica<Clave>(nceldas);
        break;
    case 4:
        g_ = new FExploracionReDispersion<Clave>(nceldas);
        break;
    default:
        cout << "ERROR, FUNCION DE EXPLORACION NO VALIDA" << endl;
        break;
    }
}

template <class Clave>
Tabla<Clave>::~Tabla()
{
    delete vCelda_;
}
template <class Clave>
bool Tabla<Clave>::Search_T(const Clave x) //Realizaremos la busqueda por metodo de busqueda binaria
{
    for (int i = 0; i < nCeldas_; i++)
        if (!vCelda_[i]->Search(x))
            return false;
        else
            return true;
}

template <class Clave>
bool Tabla<Clave>::Insert_T(const Clave &x)
{

    if (Search_T(x))
        return false;
    if (vCelda_[(*h_)(x)]->Insert(x))
    {
        return true;
    }
    else
    {
        int i = (*h_)(x);
        int limit;
        if (i == 0)
            limit = Tabla<Clave>::nCeldas_ - 1;
        else
        {
            limit = (*h_)(x)-1;
            if (limit == i)
                return false;
        }

        while (i != limit)
        {
            if (vCelda_[((*h_)(x) + (*g_)(x, i)) % nCeldas_]->Insert(x))
                return true;

            (i == nCeldas_ - 1 ? i = 0 : i++);
            if (vCelda_[((*h_)(x) + (*g_)(x, i)) % nCeldas_]->Insert(x))
                return true;
        }
    }
    return false;
}

template <class Clave>
std::ostream &Tabla<Clave>::Write(std::ostream &os)
{
    for (int i = 0; i < nCeldas_; i++)
    {
        for (int j = 0; j < nClaves_; j++)
        {
            os << "|" << vCelda_[j][0][i] << "|";
        }
        os << "\n";
    }
    return os;
}