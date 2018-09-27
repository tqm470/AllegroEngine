#include "../Headers/Teclado.h"


Teclado::Teclado()
{
    al_install_keyboard();
}

void Teclado::Atualizar()
{
    al_get_keyboard_state( &estado );
}

bool Teclado::Tecla( int keycode ) const
{
    return al_key_down( &estado, keycode );
}

Teclado::~Teclado()
{
    al_uninstall_keyboard();
}