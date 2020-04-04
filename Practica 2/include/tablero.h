#pragma once
#include <iostream>
#include "/home/user/Practica 2/include/celula.h"

using namespace std;

class tablero {
 private:
  celula **Tab;  // El tablero
  int n, m;      // Filas x Columnas

 public:
  tablero(int fila, int columna);  // Constructor
  ~tablero();                      // Destructor

  int NumCelVivas();               // Numero de celulas vivas
  void give_life(int x, int y);    // Da vida a las celulas que elejimos
  celula **get_tab() const;        // Pasa por refencia el tablero
  
  int MaxVecinas();

  void WriteTablero();             // Escribir el tablero
  void ActualizarTablero();        // Actualiza el tablero
};
