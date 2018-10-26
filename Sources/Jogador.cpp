#include "../Headers/Jogador.h"

Jogador::Jogador(const Imagem& sprite, const Vec2<float>& pos, const Mouse& mouse, const Teclado& teclado, Cena& cena )
    :
    cena(cena),
    Personagem( sprite, pos ),
    mouse( mouse ),
    teclado( teclado )
{
    spellSprite = new Sprite( "Recursos/!Other2.png", 576 / 4, 768 / 2, 3 );
    font = new Fonte("Recursos/font/Quicksand.otf", 16);
}

void Jogador::Atualizar( float dt )
{
    Personagem::Atualizar( dt );
    LerControles();
    if(castCD != 0)
    {
        castCD += dt;
        if(castCD > 0.5f)
        {
            castCD = 0.0f;
        }
    }
}

void Jogador::Desenhar() const
{
    animations[(int)sequenciaAtual].Desenhar( pos );
    font->Escrever("Player 1", pos + Vec2<float>( -10, -20 ), al_map_rgb(50, 255, 255) );
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
        if( mouse.Botao( 2 ) || teclado.Tecla( ALLEGRO_KEY_A) )
        {
            Cast( *spellSprite, (mouse.GetPosition() - pos).Normalizado(), 1.5f, 400 );
            castCD += 0.1f;
        }

    SetDirection( dir );
}

void Jogador::Cast( const Imagem& sprite, const Vec2<float>& dir, float velocidade, float alcance )
{
    GameObject* novo = new Projetil( sprite, 2, pos + Vec2<float>(20.0f, 20.0f), dir, velocidade, alcance);
    cena.CriarObjeto( novo );
}