#pragma once

#include <iostream>
using namespace std;

#include "sll_node_t.h"

template <class TDato>
class sll_t {   // Clase lista
 private:
  sll_node_t<TDato>* head_;    // head de la lista

 public:
  sll_t(void) { head_ = NULL; }  // Constructor por defecto
  ~sll_t(void) {                 // Destructor
    while (!empty()) {
      sll_node_t<TDato>* aux = head_;
      head_ = head_->get_next();
      delete aux;
    }
  }

  void insert_head(sll_node_t<TDato>* n) {
    n->set_next(head_);
    head_ = n;
  }
  sll_node_t<TDato>* extract_head(void) {
    sll_node_t<TDato>* aux = head_;
    head_ = head_->get_next();
    aux->set_next(NULL);
  }

  void insert_after(sll_node_t<TDato>* prev, sll_node_t<TDato>* n) {
    n->set_next(prev->get_next());
    prev->set_next(n);
  }
  sll_node_t<TDato>* extract_after(sll_node_t<TDato>* prev) {
    sll_node_t<TDato>* aux = prev->get_next();
    prev->set_next(aux->get_next());
    aux->set_next(NULL);
    return aux;
  }

  sll_node_t<TDato>* head(void) { return head_; }

  bool empty(void) const { return (head_ == NULL); }
  void write(ostream& os) const {
    sll_node_t<TDato>* aux = head_;
    cout << "[ ";
    while (aux != NULL) {
      cout << aux->get_data() << ", ";
      // aux->write(os);
      aux = aux->get_next();
    }
    cout << " ]" << endl;
  }
};