#pragma once

class contador
{
private:
    int cont;

public:
    contador();
    ~contador();
    void Reset();
    void Inc();
    int Get();
};