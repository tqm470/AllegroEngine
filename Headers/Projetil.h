#ifndef PROJETIL_CLASS
#define PROJETIL_CLASS
#include "Vec2.h"
#include "Anime.h"

class Projetil
{
public:
    Projetil( const Anime& animation, const Vec2<float>& pos, const Vec2<float>& dir, const float speed, float alcance );
    Projetil( const Projetil&& rhs );
    Projetil( const Projetil& rhs );
    virtual void Atualizar( const float frameTime );
    virtual void Desenhar() const;
    Projetil&& operator= ( const Projetil& rhs );
private:
    Anime animation;
    Vec2<float> pos;
    double angulo;
    const Vec2<float> pos0;
    const Vec2<float> dir;
    const float alcance;
    const float velocidade;
public:
    bool deveDeletar = false;
};

#endif