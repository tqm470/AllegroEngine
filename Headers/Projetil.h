#ifndef PROJETIL_CLASS
#define PROJETIL_CLASS
#include "GameObject.h"
#include "Vec2.h"
#include "Personagem.h"
#include "Anime.h"
#include <memory>

class Projetil : public GameObject
{
public:
    Projetil( const Imagem& sprite, int n,const Vec2<float>& pos, const Vec2<float>& dir, const float speed, float alcance );
    //Projetil( const Projetil&& rhs );
    //Projetil( const Projetil& rhs );
    void Atualizar( const float frameTime ) override;
    void Desenhar() const override;
    virtual void Colide( Personagem& alvo );
    //Projetil& operator= ( const Projetil& rhs );
private:
    Anime* animation;
    Vec2<float> pos;
    double angulo;
    const Vec2<float> pos0;
    const Vec2<float> dir;
    const float alcance;
    const float velocidade;
};

#endif