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
template<class Clave>
class Tabla {

private:
    Celda<Clave> **vCelda_;
    int nCelda_;               ////TAMAÑO DE LA TABLA
    FDispersionBase<Clave> *h_;
    FExploracionBase<Clave> *g_;

public:
    Tabla(int nceldas, int nclaves, int Fdisp, int Fexpl);
    ~Tabla();
    bool Search_T(const Clave x);
    bool Insert_T(const Clave &x);

};

template<class Clave>
Tabla<Clave>::Tabla(int nceldas, int nclaves, int Fdisp, int Fexpl) {

  nCelda_ = nceldas;
  vCelda_ = new Celda<Clave>*[nceldas];
  for(int i=0; i<nceldas; i++) {
    vCelda_[i]= new Celda<Clave>(nclaves);
    
    
  }

    switch(Fdisp)
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
            cout << "ERROR, FUNCION DE DISPERSION NO VALIDA"<< endl;
            break; 
    }
     switch(Fexpl)
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
            cout << "ERROR, FUNCION DE EXPLORACION NO VALIDA"<< endl;
            break; 
    }
}

template<class Clave>
Tabla<Clave>::~Tabla() 
{   
    delete vCelda_;
}
template<class Clave>
bool Tabla<Clave>::Search_T(const Clave x)        //Realizaremos la busqueda por metodo de busqueda binaria
{   
    if(vCelda_[(*h_)(x)+(*g_)(x)])
    /*for(int i = 0; i < nCelda_; i++)
        if(!vCelda_[i]->Search(x))
            return false;
        else
            return true;*/
}
template<class Clave>
bool Tabla<Clave>::Insert_T(const Clave &x)
{   

        for(int i = 0; i < nCelda_; i++)
            if(vCelda_[(*h_)(x)]->Insert(x))
            {   
                vCelda_[(*h_)(x)]->Insert(x); 
                    return true;
            }
    return false;
}