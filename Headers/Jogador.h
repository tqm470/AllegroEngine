#ifndef JOGADOR_CLASS
#define JOGADOR_CLASS
#include "Personagem.h"
#include "Mouse.h"
#include "Teclado.h"

class Jogo;

class Jogador : public Personagem
{
public:
    Jogador(const Imagem& sprite, const Vec2<float>& pos, const Mouse& mouse, const Teclado& teclado, Jogo& scena);
    void Atualizar( float dt ) override;
    void Cast( const Anime& sprite, const Vec2<float>& dir, float velocidade, float alcance );
    void LerControles();
private:
    Jogo& scena;
    float castCD = 0.0f;
    const Mouse& mouse;
    const Teclado& teclado;
};

#endif