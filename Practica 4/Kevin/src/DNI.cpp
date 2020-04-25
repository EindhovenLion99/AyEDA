#include "../include/DNI.hpp"

DNI::DNI():
value_(0) {}


DNI::DNI(int value):
    value_(value)
{}


DNI::DNI(const DNI& n):
    value_(n.value_)
{}


DNI::~DNI() {
    value_= 0;
}


int DNI::operator %(int n){
    return value_%n; 
}


bool DNI::operator==(DNI& n){
    return value_==n.value_; 
}


bool DNI::operator==(int n){
  return value_==n;
}


DNI& DNI::operator = (DNI& n) {
    value_= n.value_;
    return *this;
}

ostream& DNI::Print(ostream& os) const
{   
    std::string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
    if (value_ != 0)
        os << value_ << letras[value_%23];
    else
        os << "-";
    return os;
}