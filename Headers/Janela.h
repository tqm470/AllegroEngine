#ifndef JANELA_CLASS
#define JANELA_CLASS
#include "allegro5/allegro.h"

class Janela
{
public:
    Janela(int largura, int altura);
    ~Janela();
    ALLEGRO_DISPLAY* GetJanela() const;
private:
    ALLEGRO_DISPLAY* janela;
};

#endif