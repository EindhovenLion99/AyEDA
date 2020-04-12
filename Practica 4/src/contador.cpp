#include "contador.hpp"

contador::contador()
{
    cont = 0;
}

contador::~contador()
{
}

void contador::Reset()
{
    cont = 0;
}

void contador::Inc()
{
    cont++;
}

int contador::Get()
{
    return cont;
}