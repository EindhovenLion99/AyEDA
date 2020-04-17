#include "DNI.hpp"
#include "Contador.hpp"

Contador DNI::cont;
Contador DNI::Max;
Contador DNI::Min;
Contador DNI::Iter;

DNI::DNI()
{
    Dni_ = rand() % DNI_SIZE;
    valor_ = Dni_;
    
}


DNI::DNI(int seed)
{
    srand(seed);
    Dni_ = rand() % DNI_SIZE;
}


DNI::~DNI() {

}


void DNI::reset()
{
    DNI::cont.reset();
}


DNI::operator unsigned long() const
{
    return Dni_;
}


bool DNI::operator==(const DNI R_value)
{
    
    cont.increment();
    unsigned long chg = R_value;
        return Dni_ == chg;
}


bool DNI::operator<=(const DNI R_value)
{   cont.increment();
    unsigned long chg = R_value;
        return Dni_ <= chg;
}


bool DNI::operator>=(const DNI R_value)
{   cont.increment();
    unsigned long chg = R_value;
        return Dni_ >= chg;
}


bool DNI::operator!=(const DNI R_value)
{   cont.increment();
    unsigned long chg = R_value;
        return Dni_ != chg;
}


bool DNI::operator> (const DNI R_value)
{   cont.increment();
    unsigned long chg = R_value;
        return Dni_ > chg;
}


bool DNI::operator< (const DNI R_value)
{   cont.increment();
    unsigned long chg = R_value;
        return Dni_ < chg;
}


/*
int DNI::value() {
	int valueout = (int)Dni_;
	return valueout;
}*/