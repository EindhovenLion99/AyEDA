#pragma once
#include<iostream>

class Contador {

private:
    int Value_ ;
    
public:
    Contador() : Value_(1) {}
    inline void increment(void){Value_++;}
    inline void reset(void){Value_ = 1;}
    inline void decrement(void){Value_ > 0 ? Value_-- : Value_= 0;}
    inline int Get(void){return Value_;}
    inline void Set(int x){ Value_ = x;}
    void operator++(){++Value_;}
};