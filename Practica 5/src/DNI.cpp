#include "DNI.hpp"
#include "Contador.hpp"

Contador DNI::Cont_;

DNI::DNI()
{
    Valor_ = rand() % 100000000;
    longValue_ = Valor_;
    Sz_ = to_string(Valor_).length();
}

DNI::DNI(int Semilla)
{
    srand(Semilla);
    Valor_ = rand() % 100000000;
    Sz_ = to_string(Valor_).length();
}

DNI::~DNI()
{
}

int DNI::get_Cont() { return DNI::Cont_.get_Cont(); }
void DNI::Reset() { DNI::Cont_.Reset(); }

ostream &operator<<(ostream &os, DNI &dni)
{
    if (dni.get_DNI() != -1)
    {
        switch (dni.get_Sz())
        {
        case 0:
            os << "00000000" << dni.get_DNI() << " ";
            break;
        case 1:
            os << "0000000" << dni.get_DNI() << " ";
            break;
        case 2:
            os << "000000" << dni.get_DNI() << " ";
            break;
        case 3:
            os << "00000" << dni.get_DNI() << " ";
            break;
        case 4:
            os << "0000" << dni.get_DNI() << " ";
            break;
        case 5:
            os << "000" << dni.get_DNI() << " ";
            break;
        case 6:
            os << "00" << dni.get_DNI() << " ";
            break;
        case 7:
            os << "0" << dni.get_DNI() << " ";
            break;
        case 8:
            os << dni.get_DNI() << " ";
            break;

        default:
            os << "---------"
               << " ";
            break;
        }
    }
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