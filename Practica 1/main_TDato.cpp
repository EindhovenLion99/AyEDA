#include <iostream>

#include "queue_t.h"
#include "sll_t.h"
#include "stack_t.h"
#include "vector_t.h"

int main() {
  // **************************** VECTOR **************************

  cout << "******** VECTOR ************" << endl;

  vector_t<int> A(10);
  cout << "Size: " << A.size() << endl;
  for (int i = 0; i < A.size(); i++) {
    A[i] = i;
  }
  A.write();
  cout << endl;

  // ************************ LISTA ENLAZADA *********************

  cout << "******** SLL ************" << endl;

  sll_t<int> lista;
  for (int i = 0; i < 10; i++) lista.insert_head(new sll_node_t<int>(i));
  lista.extract_head();

  lista.write(cout);
  sll_node_t<int>* nodo = lista.head();
  int dato = nodo->get_data();
  cout << "El head contiene el dato: " << dato << endl << endl;

  // **************************** Pila ****************************

  cout << "******** STACK ************" << endl;

  stack_t<int> Pila(10);
  
  for(int i = 0; i < 10; i++){
    Pila.push(i);
  }

  cout << "Top: " << Pila.peek() << endl;
  cout << "Size de la pila: " << Pila.size() << endl;

  if (Pila.isEmpty())
    cout << "Pila esta vacia" << endl;
  else
    cout << "La pila no esta vacia" << endl;

  Pila.write();
  
  Pila.pop();
  Pila.pop();
  
  Pila.write();

  // **************************** COLA ****************************

  cout << "******** COLA ************" << endl;

  queue_t<int> C(10);

  C.enqueue(3);
  C.enqueue(4);
  C.enqueue(5);
  C.enqueue(6);

  int x = C.dequeue();
  int y = C.dequeue();
  cout << "x = " << x << endl << "y = " << y << endl;
  C.write();
}