#pragma once
#include <iostream>

using namespace std;

class tablero;
class celula {
 private:
  int posX;       // Posicion [x]
  int posY;       // Posicion [y]
  int vecinas;    // Las vecinas de cada celula

 public:
  static celula();                        // Constructor por defecto, vacio
  static celula(int x, int y);            // Constructor por parametros, estado, x e y
  ~celula();                              // Destructor

  int getEstado();
  int getVecinas();                       // getter del numero de vecinas
  int setVecinas(int x);                  // setter del numero de vecinas

  // int updateEstado();                     // saber si hay que actualizar la celula // REGLAS DE NACIMIENTO
  int contarVecinas(const tablero& Tab);  // Cuenta las vecinas de cada celula

  ostream& WriteCel(ostream& os) const;   // Imprime la celula
};


