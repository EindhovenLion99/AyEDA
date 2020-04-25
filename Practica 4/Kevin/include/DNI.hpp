#pragma once
#include <iostream>
#include <string>

using namespace std;


class DNI {
    private:
        int value_;
    
    public:
        DNI();
        DNI(int value);
        DNI(const DNI& n);
        ~DNI();
    
        int get_value() { return value_; }
    
        int operator %(int n);
        bool operator==(DNI& n);
        bool operator==(int n);
        DNI& operator= (DNI&);
    
        ostream& Print(ostream&) const;
};