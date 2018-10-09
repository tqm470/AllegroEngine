#include "../Headers/Projetil.h"
#include <cmath>

Projetil::Projetil( const Anime& animation, const Vec2<float>& pos, const Vec2<float>& dir,
                    const float velocidade, const float alcance )
    :
    animation(animation),
    pos(pos),
    pos0(pos),
    dir(dir),
    velocidade(velocidade),
    alcance(alcance)
{
    angulo = -std::atan2( dir.x, dir.y );
}

void Projetil::Atualizar( float dt )
{
    pos = pos + (dir * velocidade);
    if( (pos - pos0).Comprimento() < alcance )
    {
        animation.Atualizar( dt );
    }
    else
    {
        deveDeletar = true;
    }
}

void Projetil::Desenhar() const
{
        animation.DesenharRotacionado( pos, angulo );
}

Projetil::Projetil( const Projetil&& rhs )
    :
    animation(rhs.animation),
    pos(rhs.pos),
    pos0(rhs.pos0),
    dir(rhs.dir),
    velocidade(rhs.velocidade),
    alcance(rhs.alcance),
    angulo(rhs.angulo)
{

}

Projetil::Projetil( const Projetil& rhs )
    :
    animation(rhs.animation),
    pos(rhs.pos),
    pos0(rhs.pos0),
    dir(rhs.dir),
    velocidade(rhs.velocidade),
    alcance(rhs.alcance),
    angulo(rhs.angulo)
{

}

std::unique_ptr<Projetil> Projetil::operator= ( const Projetil& rhs )
{
    std::unique_ptr<Projetil> retorno( new Projetil( rhs ) );
    return std::move( retorno );
}

void Projetil::Colide( Personagem& alvo )
{
    
}