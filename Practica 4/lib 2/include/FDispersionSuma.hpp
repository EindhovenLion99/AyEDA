#pragma once
#include "FDispersionBase.hpp"

template<class Clave>
class FDispersionSuma : public
FDispersionBase<Clave>{

private:


public:
    FDispersionSuma(const int nceldas);
    ~FDispersionSuma();
    int operator()(const Clave &x);
};

template<class Clave>
FDispersionSuma<Clave>::FDispersionSuma(const int nceldas) {
    FDispersionBase<Clave>::T_ = nceldas; 
}

template<class Clave>
FDispersionSuma<Clave>::~FDispersionSuma() {

}

template<class Clave>
int FDispersionSuma<Clave>::operator()(const Clave &x) { 
  unsigned long d = 0 ;
  unsigned long p = x;
  unsigned long y;
  while (p > 0) { 
      y = p % 10;
      d = d + y;
      p = p / 10;
  } 
  return (d % FDispersionBase<Clave>::T_);
}