#include <iostream>
#include "/home/user/Practica 2/include/celula.h"
#include "/home/user/Practica 2/include/tablero.h"

using namespace std;

int main() {
  cout << "Introduce el numero de filas: ";   // Filas de la malla
  int filas;
  cin >> filas;

  cout << "Introduce el numero de columnas: ";  // Columnas de la malla
  int columnas;
  cin >> columnas;

  tablero T(filas + 2, columnas + 2);       // Creamos el tablero T

  int cvivas;
  cout << endl << "Introduce el numero de celulas vivas: ";    // Seleccionamos celulas vivas
  cin >> cvivas;

  cout << endl;

  int x, y;
  for (int i = 0; i < cvivas; i++) {
    cout << "Introduce la coordenada x: ";    // Coordenada X de las celulas vivas
    cin >> x;
    cout << "Introduce la coordenada y: ";    // Coordenada X de las celulas vivas
    cin >> y;

    cout << endl;

    T.give_life(x, y);                        // Damos vida a las celulas
  }
  T.ActualizarTablero();                      // Metodo Principal del juego
}
