#ifndef BUG_CLASS
#define BUG_CLASS
#include <iostream>

class Bug
{
public:
    Bug(const char * erro)
        :
        erro(erro)
    {
    }
    void Print() const
    {
        std::cout << erro << std::endl;
    }
    const char * GetErro() const
    {
        return erro;
    }
    
private:
    const char* erro;
};

#endif