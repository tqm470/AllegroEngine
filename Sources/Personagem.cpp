#include "../Headers/Personagem.h"

Personagem::Personagem( const Imagem& sprite, Vec2<float> pos )
    :
    sprite(sprite),
    pos(pos)
{
    for( int i = 0; i < (int)Sequencia::ParadoBaixo; i++ )
    {
        animations.push_back( Anime(0, 48 * i, 48, 48, 3, sprite, 0.16f ) );
    }
    for( int i = (int)Sequencia::ParadoBaixo; i < (int)Sequencia::Contador; i++)
    {
        animations.push_back( Anime(48, 48 * (i - (int)Sequencia::ParadoBaixo), 48, 48, 1, sprite, 0.16f ) );
    }
}

void Personagem::Desenhar() const
{
    animations[(int)sequenciaAtual].Desenhar( pos );
}

void Personagem::Atualizar( float dt )
{
    pos = pos + dir;
    animations[(int)sequenciaAtual].Atualizar( dt );
}

void Personagem::SetDirection( const Vec2<float>& direction )
{
    if(direction.x > 0.0f)
    {
        sequenciaAtual = Sequencia::AndandoDireita;
    }
    else if(direction.x < 0.0f)
    {
        sequenciaAtual = Sequencia::AndandoEsquerda;
    }
    else if(direction.y > 0.0f)
    {
        sequenciaAtual = Sequencia::AndandoBaixo;
    }
    else if(direction.y < 0.0f)
    {
        sequenciaAtual = Sequencia::AndandoCima;
    }

    else
    {
        if(dir.x > 0 )
        {
            sequenciaAtual = Sequencia::ParadoDireita;
        }
        else if(dir.x < 0 )
        {
            sequenciaAtual = Sequencia::ParadoEsquerda;
        }
        else if(dir.y > 0 )
        {
            sequenciaAtual = Sequencia::ParadoBaixo;
        }
        else if(dir.y < 0 )
        {
            sequenciaAtual = Sequencia::ParadoCima;
        }
    }
    dir = direction * velocidade;
}

Vec2<float> Personagem::GetPos() const
{
    return pos;
}

Personagem::~Personagem()
{
}