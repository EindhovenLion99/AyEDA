#pragma once
#include <iostream>
#include "celula.h"

using namespace std;

class celula1 : public celula {
  public:
  int updateEstado();
  int getEstado();
  ostream& WriteCel(ostream& os) const;
};

celula1::celula1(int x, int y){}

int updateEstado(){
  
}

int celula::getEstado(){
  return 1;
}

ostream& celula::WriteCel(ostream& os) const {
    os << " 1 ";
}