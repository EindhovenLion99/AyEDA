#include <iostream>
#include "sll_t.h"
#include "vector_t.h"

using namespace std;

struct profesor{
  profesor(string name, string DNI) {
    name = name_;
    DNI = DNI_;
  }
  string name_;
  string DNI_;
};

struct asignatura{
  asignatura(string name, string code){
    name = name_;
    code = code_;
  }
  string code_;
  string name_;
  sll_t<profesor> profes;
};

void ver_Profesorado(vector_t<asignatura> a, string codigo){
  for(int i = 0; i < a.size(); i++){
    if(codigo == a[i].code_){
      cout << "Asignatura: " << a[i].name_ << endl;
      sll_node_t<profesor>* aux = a[i].profes.head();
      while(aux != NULL) {
        cout << aux->get_data().name_ << aux->get_data().DNI_;
        aux = aux->get_next();
      }
    }
  }
}

int main(){
  profesor Alberto("Alberto", "4327233F"), Vanessa("Vanessa", "84728472F");
  asignatura CDYAL("CDYAL", "345212"), AYEDA("AYEDA", "43323243");
  AYEDA.profes.insert_head(Alberto);
  AYEDA.profes.insert_head(Vanessa);

  vector_t<asignatura> Vector(2);

  Vector[0] = CDYAL;
  Vector[1] = AYEDA;
  
  ver_Profesorado(Vector, "43323243");
}