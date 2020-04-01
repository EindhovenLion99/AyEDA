#pragma once
#include <iostream>
#include "celula.h"

using namespace std;

class celula3 : public celula {
  public:
  int updateEstado();
  ostream& WriteCel(ostream& os) const;
};

celula3::celula3(int x, int y){}

int updateEstado(){
  
}

int celula::getEstado(){
  return 3;
}

ostream& celula::WriteCel(ostream& os) const {
    os << " 3 ";
}