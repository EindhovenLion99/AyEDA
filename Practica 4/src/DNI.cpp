#include "DNI.hpp"
#include <iostream>

DNI::DNI()
{
}

DNI::~DNI()
{
}

DNI::operator unsigned long() const
{
    return valor;
}

bool DNI::operator==(const DNI a) const
{
    if (valor == a.valor)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DNI::operator>=(const DNI a) const
{
    if (valor == a.valor)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DNI::operator<=(const DNI a) const
{
    if (valor == a.valor)
    {
        return true;
    }
    else
    {
        return false;
    }
}
