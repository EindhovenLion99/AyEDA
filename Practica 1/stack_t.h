#pragma once

#include <iostream>
using namespace std;

template <class TDato>

class stack_t {
 private:
  TDato *arr;
  TDato top;
  int capacity;

 public:
  stack_t(int size) {  // Constructor
    arr = new TDato[size];
    capacity = size;
    top = -1;
  }
  ~stack_t() { delete arr; }  // Destrcutor

  void push(int x) {
    if (isFull()) {
      cout << "OverFlow" << endl << "Programa terminado" << endl;
      exit(EXIT_FAILURE);
    }
    cout << "Pushing: " << x << endl;
    arr[++top] = x;
  }

  TDato pop() {
    if (isEmpty()) {
      cout << "OverFlow" << endl << "Programa terminado" << endl;
      exit(EXIT_FAILURE);
    }
    cout << "Poping " << peek() << endl;
    return arr[top--];
  }

  TDato peek() {
    if (!isEmpty())
      return arr[top];
    else
      exit(EXIT_FAILURE);
  }

  int size() { return top + 1; }

  bool isEmpty() { return top == -1; }
  bool isFull() { return top == capacity - 1; }

  void write() {
    cout << "_______" << endl << endl;
    for (int i = top; i >= 0; i--) {
      cout << "   " << arr[i] << endl;
    }
    cout << "_______" << endl;
  }
};