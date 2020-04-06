#pragma once
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class vector_t {
 private:
  T* v_;
  int sz_;

 public:
  vector_t(void) : v_(NULL), sz_(0) {}

  vector_t(int sz) : v_(NULL), sz_(sz) { v_ = new T[sz_]; }

  vector_t(const vector_t& v) {
    v_ = new T[sz_];
    for (int i = 0; i < sz_; i++) v_[i] = v.v_[i];
  }

  vector_t& operator=(const vector_t& v) {
    resize(v.sz_);
    for (int i = 0; i < sz_; i++) v_[i] = v.v_[i];
  }

  ~vector_t(void) { destruye_vector(); }

  void resize(int sz) {
    destruye_vector();
    sz_ = sz;
    v_ = new T[sz_];
  }

  int size(void) const { return sz_; }

  const T& at(int pos) const {
    assert((pos < sz_) && ((pos >= 0)));
    return v_[pos];
  }

  T& at(int pos) {
    assert((pos < sz_) && ((pos >= 0)));
    return v_[pos];
  }

  const T& operator[](int pos) const { return at(pos); }

  T& operator[](int pos) { return at(pos); }

  void write(){
    cout << "[ ";
    for(int i = 0; i < sz_; i++){
      cout << v_[i] << ", ";
    }
    cout << " ]" << endl;
  }

 private:
  void destruye_vector(void) {
    if (v_ != NULL) {
      delete[] v_;
      v_ = NULL;
    }
  }
};
