#pragma once

class DNI
{
private:
    unsigned long valor;

public:
    DNI();
    ~DNI();
    operator unsigned long() const;
    bool operator==(const DNI a) const;
    bool operator<=(const DNI a) const;
    bool operator>=(const DNI a) const;
};