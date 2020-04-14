#include "DNI.hpp"
#include "contador.hpp"
#include <iostream>

contador DNI::cont;

DNI::DNI()
{
}

DNI::~DNI()
{
}

DNI::operator unsigned long() const
{
    return long_valor;
}

int DNI::compara() { return DNI::cont.Get(); }
void DNI::reset() { DNI::cont.Reset(); }

bool DNI::operator==(DNI &a)
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

bool DNI::operator>=(DNI &a)
{
    if (valor >= a.val())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DNI::operator<=(DNI &a)
{
    if (valor <= a.val())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DNI::operator>(DNI &a)
{
    if (valor > a.val())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DNI::operator<(DNI &a)
{
    if (valor < a.val())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DNI::operator<(DNI &a)
{
    if (valor < a.val())
    {
        return true;
    }
    else
    {
        return false;
    }
}
