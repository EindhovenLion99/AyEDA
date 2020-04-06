#include <iostream>
#include "/home/user/Practica 3/include/celula.h"
#include "/home/user/Practica 3/include/tablero.h"
using namespace std;

celula::celula() {}

celula::celula(int x, int y) {
  posX = x;
  posY = y;
}

celula::~celula() {}

/*

int celula::setEstado(int value) { estado_ = value; }

int celula::getEstado() { return estado_; }

int celula::setVecinas(int x){
  vecinas = x;
}

*/

int celula::contarVecinas(const tablero& Tab) {
  celula** mapa = Tab.get_tab();
  int vecinas = 0;

  for (int i = posX - 1; i <= posX + 1; i++) {
    for (int j = posY - 1; j <= posY + 1; j++) {
      if ((i != posX) || (j != posY)) {            // Evitamos que se cuente la propia celula
        if (mapa[i][j].getEstado() == 1) vecinas++;
      }
    }
  }

  return vecinas;
}

int celula::getEstado(){
  return 0;
}

/*
int celula::updateEstado() {   // Debe retornar el tipo de celula que revive
  int status;
  if ((estado_ == 1) && (vecinas == 2) || (vecinas== 3)) {
    status = 1;
  } else if ((estado_ == 0) && (vecinas == 3)) {
    status = 1;
  } else {
    status = 0;
  }

  return status;
}
*/

ostream& celula::WriteCel(ostream& os) const {
    os << " · ";
}