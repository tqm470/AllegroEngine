#include "../Headers/Jogador.h"

Jogador::Jogador(const Imagem& sprite, const Vec2<float>& pos, const Mouse& mouse, const Teclado& teclado)
    :
    Personagem( sprite, pos ),
    mouse( mouse ),
    teclado( teclado )
{

}

void Jogador::Atualizar( float dt )
{
    Personagem::Atualizar( dt );
    LerControles();
}

void Jogador::LerControles()
{
    Vec2<float> dir = {0.0f, 0.0f};

    if( teclado.Tecla( ALLEGRO_KEY_UP ) )
    {
        dir = { 0.0f, -1.0f };
    }
    else if( teclado.Tecla( ALLEGRO_KEY_DOWN ) )
    {
        dir = { 0.0f, 1.0f };
    }
    else if( teclado.Tecla( ALLEGRO_KEY_LEFT ) )
    {
        dir = { -1.0f, 0.0f };
    }
    else if( teclado.Tecla( ALLEGRO_KEY_RIGHT ) )
    {
        dir = { 1.0f, 0.0f };
    }

    SetDirection( dir );
}