#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Contador.hpp"

using namespace std;

class ISBN
{
private:
    int cod_;
    unsigned long longcod_;

public:
    ISBN();
    ISBN(int Semilla);
    ~ISBN();

    static Contador Cont_;

    inline int get_Book() const { return cod_; }
    inline void set_Book(int val) { cod_ = val; }

    inline void set_Empty() { cod_ = -1; }

    ostream &Print(ostream &) const;

    bool operator==(ISBN &Val);
    bool operator!=(ISBN &Val);
    bool operator>(ISBN &Val);
    bool operator<(ISBN &Val);
    bool operator<=(ISBN &Val);
    bool operator>=(ISBN &Val);

    operator unsigned long() const;
};

ISBN::ISBN()
{
    cod_ = rand() % 10000000000;
    longcod_ = cod_;
}

ISBN::ISBN(int Semilla)
{
    srand(Semilla);
    cod_ = rand() % 10000000000;
}

ISBN::~ISBN()
{
}

ostream &ISBN::Print(std::ostream &os) const
{
    if (cod_ != -1)
    {
        os << get_Book() << " ";
    }
    else
        os << "-";
    return os;
}

bool ISBN::operator==(ISBN &Val)
{
    Cont_++;
    return get_Book() == Val.get_Book();
}

bool ISBN::operator!=(ISBN &Val)
{
    Cont_++;
    return get_Book() != Val.get_Book();
}

bool ISBN::operator>=(ISBN &Val)
{
    Cont_++;
    return get_Book() == Val.get_Book();
}

bool ISBN::operator<=(ISBN &Val)
{
    Cont_++;
    return get_Book() <= Val.get_Book();
}

bool ISBN::operator>(ISBN &Val)
{
    Cont_++;
    return get_Book() > Val.get_Book();
}

bool ISBN::operator<(ISBN &Val)
{
    Cont_++;
    return get_Book() < Val.get_Book();
}

ISBN::operator unsigned long() const
{
    return longcod_;
}