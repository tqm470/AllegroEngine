#ifndef TELCADO_CLASS
#define TELCADO_CLASS
#include <allegro5/allegro5.h>

class Teclado
{
public:
    Teclado();
    ~Teclado();
    bool Tecla( int keycode ) const;
    void Atualizar();
private:
    ALLEGRO_KEYBOARD_STATE estado;
};

#endif