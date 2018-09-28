#include "../Headers/Mouse.h"

Mouse::Mouse()
{
    if(!al_install_mouse())
    {
        throw Bug("Erro ao instalar o driver do mouse!");
    }
    
}

void Mouse::Atualizar()
{
    al_get_mouse_state(&estado);
}

Vec2<float> Mouse::GetPosition() const
{
    return {(float)estado.x, (float)estado.y};
}

bool Mouse::Botao( int botao ) const
{
    if(estado.buttons & botao)
        return true;
    else   
        return false;
}

Mouse::~Mouse()
{
    al_uninstall_mouse();
}