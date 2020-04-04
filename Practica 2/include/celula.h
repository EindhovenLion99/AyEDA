#pragma once
#include <iostream>

using namespace std;

class tablero;
class celula {
 private:
  int estado_;    // Viva o muerta
  int posX;       // Posicion [x]
  int posY;       // Posicion [y]
  int vecinas;    // Las vecinas de cada celula

 public:
  celula();                               // Constructor por defecto, vacio
  celula(int estado, int x, int y);       // Constructor por parametros, estado, x e y
  ~celula();                              // Destructor

  int getEstado();                        // getter del estado
  int setEstado(int value);               // setter del estado

  int getVecinas();                       // getter del numero de vecinas
  int setVecinas(int x);                  // setter del numero de vecinas

  int updateEstado();                     // saber si hay que actualizar la celula
  int contarVecinas(const tablero& Tab);  // Cuenta las vecinas de cada celula

  ostream& WriteCel(ostream& os) const;   // Imprime la celula
};

