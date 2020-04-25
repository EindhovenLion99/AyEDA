#pragma once
#include <string>

    
template <class Clave> class H {
protected:
    std::string cadena;

public: 
    H(){};
    virtual ~H(){};
    virtual int operator()(Clave&, int)=0;
    inline virtual std::string get_fdisp(void){ return cadena; }
};
    