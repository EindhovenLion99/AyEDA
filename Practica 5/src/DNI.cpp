#include "DNI.hpp"
#include "Contador.hpp"

Contador DNI::Cont_;

DNI::DNI()
{
    Valor_ = rand() % 100000000;
    longValue_ = Valor_;
}

DNI::DNI(int Semilla)
{
    srand(Semilla);
    Valor_ = rand() % 100000000;
}

DNI::~DNI()
{
}

int DNI::get_Cont() { return DNI::Cont_.get_Cont(); }
void DNI::Reset() { DNI::Cont_.Reset(); }

ostream &DNI::Print(ostream &os) const
{
    if (Valor_ != -1)
        os << Valor_;
    else
        os << "-";
    return os;
}

bool DNI::operator==(DNI &Val)
{
    DNI::Cont_.Suma();
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator!=(DNI &Val)
{
    DNI::Cont_.Suma();
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator>=(DNI &Val)
{
    DNI::Cont_.Suma();
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator<=(DNI &Val)
{
    DNI::Cont_.Suma();
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator>(DNI &Val)
{
    DNI::Cont_.Suma();
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator<(DNI &Val)
{
    DNI::Cont_.Suma();
    return get_DNI() == Val.get_DNI();
}

DNI::operator unsigned long() const
{
    return longValue_;
}

void DNI::Plus()
{
    Cont_.Suma();
}