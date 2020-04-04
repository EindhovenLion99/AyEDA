#include <iostream>
#include "/home/user/Practica 2/include/tablero.h"
using namespace std;

tablero::tablero(int fila, int columna) {
  n = fila;
  m = columna;
  Tab = new celula*[n];
  for (int i = 0; i < n; i++) {
    Tab[i] = new celula[m];
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      Tab[i][j] = celula(0, i, j);
    }
  }
}

tablero::~tablero() {}

void tablero::give_life(int x, int y) { Tab[x][y].setEstado(1); }

celula** tablero::get_tab() const { return Tab; }

int tablero::NumCelVivas() {
  int cont = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (Tab[i][j].getEstado() == 1) cont++;
    }
  }

  return cont;
}

void tablero::WriteTablero() {
  for (int i = 1; i < n - 1; i++) {
    cout << "|";
    for (int j = 1; j < m - 1; j++) {
      Tab[i][j].WriteCel(cout);
    }
    cout << "|" << endl;
  }
  cout << endl;
}

int tablero::MaxVecinas() {
  int x, y = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      x = Tab[i][j].contarVecinas(*this);
      if(x > y){
        y = x;
      }
    }
  }
  return y;
}

void tablero::ActualizarTablero() {
  int nturnos, x;
  cout << "Introduzca el numero de turnos: ";
  cin >> nturnos;
  cout << endl;

  for (int i = 0; i < nturnos; i++) {
    WriteTablero();

    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        x = Tab[i][j].contarVecinas(*this);
        Tab[i][j].setVecinas(x);
      }
    }

    cout << "El numero maximo de vecinas en este turno es: " << MaxVecinas() << endl << endl;

    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        x = Tab[i][j].updateEstado();
        Tab[i][j].setEstado(x);
      }
    }

    if (NumCelVivas() == 0) {
      WriteTablero();
      break;
    }
  }
}
