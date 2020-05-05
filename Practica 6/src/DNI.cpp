#include "DNI.hpp"
#include "Contador.hpp"

Contador DNI::Cont_;

DNI::DNI()
{
    Valor_ = rand() % 99999999;
    longValue_ = Valor_;
    Sz_ = to_string(Valor_).length();
}

DNI::~DNI()
{
}

// int DNI::get_Cont() { return DNI::Cont_.get_Cont(); }
// void DNI::Reset() { DNI::Cont_.Reset(); }

ostream &DNI::Print(ostream &os) const
{
    if (get_DNI() != -1)
    {
        switch (get_Sz())
        {
        case 0:
            os << "00000000" << get_DNI() << " ";
            break;
        case 1:
            os << "0000000" << get_DNI() << " ";
            break;
        case 2:
            os << "000000" << get_DNI() << " ";
            break;
        case 3:
            os << "00000" << get_DNI() << " ";
            break;
        case 4:
            os << "0000" << get_DNI() << " ";
            break;
        case 5:
            os << "000" << get_DNI() << " ";
            break;
        case 6:
            os << "00" << get_DNI() << " ";
            break;
        case 7:
            os << "0" << get_DNI() << " ";
            break;
        case 8:
            os << get_DNI() << " ";
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

bool DNI::operator==(const DNI &Val)
{
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator>(const DNI &Val)
{
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator<(const DNI &Val)
{
    return get_DNI() == Val.get_DNI();
}

DNI::operator unsigned long() const
{
    return longValue_;
}