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

    // ********* MODIFICACION
    /*
    for (int i = 0; i < 4; i++) //generamos los 4 numeros
    {
        Matricula.at(i) = numeros[rand() % numeros.length()];
    }
    for (int i = 4; i < 7; i++) //generamos las 3 letras
    {
        Matricula.at(i) = letrasma[rand() % letrasma.length()];
    }
    Matricula.at(7) = '\0';
    */
}

DNI::DNI(int seed)
{
    srand(seed);
    Dni_ = rand() % DNI_SIZE;
}

DNI::~DNI()
{
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
    return value() == R_value.value();
    // Modificacion - > return matr() == R_value.matr();
}

bool DNI::operator<=(const DNI R_value)
{
    cont.increment();
    return value() <= R_value.value();
    // Modificacion - > return matr() <= R_value.matr();
}

bool DNI::operator>=(const DNI R_value)
{
    cont.increment();
    return value() >= R_value.value();
    // Modificacion - > return matr() >= R_value.matr();
}

bool DNI::operator!=(const DNI R_value)
{
    cont.increment();
    return value() != R_value.value();
    // Modificacion - > return matr() != R_value.matr();
}

bool DNI::operator>(const DNI R_value)
{
    cont.increment();
    return value() > R_value.value();
    // Modificacion - > return matr() > R_value.matr();
}

bool DNI::operator<(const DNI R_value)
{
    cont.increment();
    return value() < R_value.value();
    // Modificacion - > return matr() < R_value.matr();
}
