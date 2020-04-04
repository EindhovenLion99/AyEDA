#pragma once
#include <iostream>
#include "celula.h"

using namespace std;

class celula2 : public celula {
  public:
  int updateEstado();
  ostream& WriteCel(ostream& os) const;
};

celula2::celula2(int x, int y){}

int updateEstado(){
  
}

int celula::getEstado(){
  return 2;
}

ostream& celula::WriteCel(ostream& os) const {
    os << " 2 ";
}