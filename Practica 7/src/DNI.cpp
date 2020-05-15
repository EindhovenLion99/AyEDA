#include "DNI.hpp"
#include "Contador.hpp"

Contador DNI::Cont;

DNI::DNI()
{
    Valor_ = rand() % 99999999;
    longValue_ = Valor_;
}

DNI::DNI(int Num)
{
    Valor_ = Num;
    longValue_ = Valor_;
}

DNI::~DNI()
{
}

ostream &DNI::Print(ostream &os) const
{
    if (get_DNI() != -1)
    {
        int SZ = to_string(Valor_).length();
        switch (SZ)
        {
        case 0:
            os << "0000000" << get_DNI();
            break;
        case 1:
            os << "0000000" << get_DNI();
            break;

        case 2:
            os << "000000" << get_DNI();
            break;

        case 3:
            os << "00000" << get_DNI();
            break;

        case 4:
            os << "0000" << get_DNI();
            break;

        case 5:
            os << "000" << get_DNI();
            break;

        case 6:
            os << "00" << get_DNI();
            break;

        case 7:
            os << "0" << get_DNI();
            break;

        case 8:
            os << get_DNI();
            break;

        default:
            os << " XXXXXXXX ";
            break;
        }
    }
    else
        os << "-";
    return os;
}

DNI &DNI::operator=(DNI &Val)
{
    Valor_ = Val.Valor_;
    return *this;
}

bool DNI::operator==(const DNI &Val)
{
    ++Cont;
    return get_DNI() == Val.get_DNI();
}

bool DNI::operator>(const DNI &Val)
{
    ++Cont;
    return get_DNI() > Val.get_DNI();
}

bool DNI::operator<(const DNI &Val)
{
    ++Cont;
    return get_DNI() < Val.get_DNI();
}

DNI::operator unsigned long() const
{
    return longValue_;
}