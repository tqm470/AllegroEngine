#include "../Headers/Jogador.h"
#include "../Headers/Jogo.h"

Jogador::Jogador(const Imagem& sprite, const Vec2<float>& pos, const Mouse& mouse, const Teclado& teclado, Jogo& scena )
    :
    scena(scena),
    Personagem( sprite, pos ),
    mouse( mouse ),
    teclado( teclado )
{

}

void Jogador::Atualizar( float dt )
{
    Personagem::Atualizar( dt );
    LerControles();
    if(castCD != 0)
    {
        castCD += dt;
        if(castCD > 1.0f)
        {
            castCD = 0.0f;
        }
    }
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
    if(castCD == 0)
        if( teclado.Tecla( ALLEGRO_KEY_T ) )
        {
            Cast( *(scena.foguinho), (mouse.GetPosition() - pos).Normalizado(), 1.5f, 400 );
            castCD += 0.1f;
        }

    SetDirection( dir );
}

void Jogador::Cast( const Anime& sprite, const Vec2<float>& dir, float velocidade, float alcance )
{
    std::unique_ptr<Projetil> novo(new Projetil( sprite, pos + Vec2<float>(20.0f, 20.0f), dir, velocidade, alcance ));
    scena.CriarProjetil( std::move( novo ) );
}