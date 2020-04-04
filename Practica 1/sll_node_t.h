#pragma once
#include <iostream>

using namespace std;

template <class TDato>
class sll_node_t {     // Clase nodo de la lista
 private:
  sll_node_t<TDato>* next_;   // Siguiente nodo
  TDato data_;                // Dato del nodo

 public:
  sll_node_t(void);           // Constructor Vacio
  sll_node_t(TDato data){     // Constructor por parametro
    data_ = data;
  }
  ~sll_node_t(void){          // Destrcutor
    next_ = NULL;
  }

  void set_next(sll_node_t<TDato>* next){     // Set del siguiente nodo
    next_ = next;
  }
  sll_node_t<TDato>* get_next(void) const {   // Get del siguiente
    return next_;
  }

  void set_data(const TDato& data){           // Set del dato del nodo
    data_ = data;
  }
  TDato get_data(void) const {                // Get del dato del nodo
    return data_;
  }

  ostream& write(ostream& os) const {         // Write del dato del nodo
    os << data_;
    return os;
  }
};
