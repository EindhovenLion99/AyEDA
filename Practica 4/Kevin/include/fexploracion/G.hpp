#include <string>

#pragma once

template <class Clave> class G {
    protected:
        std::string cadena;
    public:
        G(){};
        virtual ~G(){};
        virtual int operator()(Clave& x, int, int)=0;
        virtual std::string get_fexp(void){return cadena;}
};
    
